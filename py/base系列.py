#1、解base64
import base64

encoded_string = "ZmxhZzp7IkhhcHB5IE1pZC1BdXR1bW4gRmVzdGl2YWwifQ==" 

decoded_string = (base64.b64decode(encoded_string)).decode()
print(decoded_string)


# #1、base64加密
# import base64

# decode_string = "Hello world!"
# encoded_string = base64.b64encode(decode_string.encode()).decode()
# print(encoded_string)


# #3、换表base64
# from base64 import b64decode

# target = "g84Gg6m2ATtVeYqUZ9xRnaBpBvOVZYtj+Tc="#密文
# oldTable = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="#旧表
# newTable = "WHydo3sThiS7ABLElO0k5trange+CZfVIGRvup81NKQbjmPzU4MDc9Y6q2XwFxJ/="#新表
# ori = target.translate(str.maketrans(newTable,oldTable))

# flag = b64decode(ori).decode()
# print(flag)