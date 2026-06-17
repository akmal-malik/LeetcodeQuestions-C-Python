IP_address = input("Enter an IP address: ")

deformed_IP = ""


for ch in IP_address:
    if ch == ".":
        deformed_IP += "[.]"
    else:
        deformed_IP += ch


print("Deformed IP address:", deformed_IP)