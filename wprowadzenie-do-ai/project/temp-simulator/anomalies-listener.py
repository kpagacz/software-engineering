from azure.servicebus import ServiceBusClient, ServiceBusMessage
import time

# Add the connection string!
CONNECTION_STR = "Endpoint=sb://kpagacz-ai.servicebus.windows.net/;SharedAccessKeyName=listener;SharedAccessKey=mgr/ViDgc3B9BYbmcl/VJQ87V0NlKt2fwCPfe3HuAB0=;EntityPath=anomalies-queue"
QUEUE_NAME = "anomalies-queue"

if CONNECTION_STR == "":
    raise ValueError("Connection string not provided. Please, modify the connection string in the script")

servicebus_client = ServiceBusClient.from_connection_string(conn_str=CONNECTION_STR, logging_enable=True)

while(True):
  with servicebus_client:
      receiver = servicebus_client.get_queue_receiver(queue_name=QUEUE_NAME, max_wait_time=5)
      with receiver:
          for msg in receiver:
              print("Received: " + str(msg))
              receiver.complete_message(msg)

  time.sleep(1)
