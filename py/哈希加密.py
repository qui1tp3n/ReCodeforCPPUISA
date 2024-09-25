#1、计算字符串哈希
from hashlib import md5
#更改哈希算法：选中'md5'修改所有匹配项
def generate_md5_hashCode(plainText):
    plainTextBytes = plainText.encode('utf-8') # 字符串在哈希之前，需要编码
    encryptor = md5()      
    encryptor.update(plainTextBytes)   
    hashCode = encryptor.hexdigest() 
    print(hashCode)
 
if __name__ == "__main__":
    generate_md5_hashCode('123456')#更改加密字符串
    
    
    
# #2、计算文件哈希
# from hashlib import sha256
 
# def generate_sha256_hashCode(filePath):
#     with open(filePath, encoding="utf-8") as f:
#         plainText = f.read()
#     plainTextBytes = plainText.encode('utf-8')
#     encryptor = sha256()   
#     encryptor.update(plainTextBytes) 
#     hashCode = encryptor.hexdigest() 
#     print(hashCode)
 
# if __name__ == "__main__":
#     generate_sha256_hashCode('test.txt')

