from azure.iot.device import IoTHubDeviceClient
import time
import json
import random
import keyboard

# Add the connection string!
CONNECTION_STR = "HostName=UL-ai-iot-hub.azure-devices.net;DeviceId=test;SharedAccessKey=yI0vNS/0MhUS9RKEISjhM+l7wqhL/U4lmUEgbplxgGo="

if CONNECTION_STR == "":
    raise ValueError("Connection string not provided. Please, modify the connection string in the script")

def send_single_message(sender, value):
  current_time = time.strftime("%Y-%m-%dT%H:%M:%S.0000000Z", time.localtime())
  load = {
    "time": current_time,
    "value": value
  }
  sender.send_message(json.dumps(load))
  print("Normal value sent")

device_client = IoTHubDeviceClient.create_from_connection_string(CONNECTION_STR)

def callback(event):
  send_single_message(device_client, 700)
  print("Anomalous value sent")

keyboard.on_press_key("s", callback)
while (True):
  send_single_message(device_client, random.randrange(30, 40))
  time.sleep(2)
