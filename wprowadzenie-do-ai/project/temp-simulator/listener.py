from azure.servicebus import ServiceBusClient, ServiceBusMessage
import time

# Add the connection string!
CONNECTION_STR = "Endpoint=sb://kpagacz-ai.servicebus.windows.net/;SharedAccessKeyName=iothubroutes_UL-ai;SharedAccessKey=fZ0wcw1D2gygqFFzlgV5AU7MvjItPumvVqDgUqCV39M=;EntityPath=edge-queue"
QUEUE_NAME = "edge-queue"

if CONNECTION_STR == "":
    raise ValueError("Connection string not provided. Please, modify the connection string in the script")

def send_single_message(sender):
    message = ServiceBusMessage("Single Message")
    sender.send_messages(message)
    print("Sent a single message")

def send_a_list_of_messages(sender):
    messages = [ServiceBusMessage("Message in list") for _ in range(5)]
    sender.send_messages(messages)
    print("Sent a list of 5 messages")

def send_batch_message(sender):
    batch_message = sender.create_message_batch()
    for _ in range(10):
        try:
            batch_message.add_message(ServiceBusMessage("Message inside a ServiceBusMessageBatch"))
        except ValueError:
            # ServiceBusMessageBatch object reaches max_size.
            # New ServiceBusMessageBatch object can be created here to send more data.
            break
    sender.send_messages(batch_message)
    print("Sent a batch of 10 messages")

servicebus_client = ServiceBusClient.from_connection_string(conn_str=CONNECTION_STR, logging_enable=True)

# with servicebus_client:
#     sender = servicebus_client.get_queue_sender(queue_name=QUEUE_NAME)
#     with sender:
#         send_single_message(sender)
#         send_a_list_of_messages(sender)
#         send_batch_message(sender)

# print("Done sending messages")
# print("-----------------------")

while(True):
  with servicebus_client:
      receiver = servicebus_client.get_queue_receiver(queue_name=QUEUE_NAME, max_wait_time=5)
      with receiver:
          for msg in receiver:
              print("Received: " + str(msg))
              receiver.complete_message(msg)
