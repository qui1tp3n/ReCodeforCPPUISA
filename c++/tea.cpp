//tea
// #include <stdio.h>  
// #include <stdint.h>  
  
// //加密函数  
// void encrypt (uint32_t* v, uint32_t* k) {  
//     uint32_t v0=v[0], v1=v[1], sum=0, i;           /*将传进函数的v分解成两个32位无符号数v0，v1 */  
//     uint32_t delta=0x9e3779b9;                     /*使用的加密常数，为黄金分割率，题目一般会改 */  
//     uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];   /* 密钥分别取出，方便后续的操作 */  
//     for (i=0; i < 32; i++) {                       /* 32轮*/  
//         sum += delta;  
//         v0 += ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);  
//         v1 += ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);  
//     }                                           
//     v[0]=v0; v[1]=v1;  //将加密完毕的两个数值放回
// }  
// //解密函数  
// void decrypt (uint32_t* v, uint32_t* k) {  
//     uint32_t v0=v[0], v1=v[1], sum=0xC6EF3720, i;  /*此处的sum是由一开始的黄金分割率迭代32轮之后得到的数*/  
//     uint32_t delta=0x9e3779b9;                     
//     uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];   /* key不变 */  
//     for (i=0; i<32; i++) {                         /* 依然是32轮*/  
//         v1 -= ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);  	//加密是加，解密即是减，由图可知，先解v1再解v0
//         v0 -= ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);  
//         sum -= delta;  
//     }                                           
//     v[0]=v0; v[1]=v1;  
// }  
  
// int main()  
// {  
//     uint32_t v[2]={1,2},k[4]={2,2,3,4};  
//     // v为要加密的数据是两个32位无符号整数  
//     // k为加密解密密钥，为4个32位无符号整数，即密钥长度为128位  
//     printf("加密前原始数据：%u %u\n",v[0],v[1]);  
//     encrypt(v, k);  
//     printf("加密后的数据：%u %u\n",v[0],v[1]);  
//     decrypt(v, k);  
//     printf("解密后的数据：%u %u\n",v[0],v[1]);  
//     return 0;  
// }  

//liti
// #include <stdio.h>
// unsigned int data1=0x5F797274;
// unsigned int data2=0x64726168;

// void decrypto(unsigned int *cipher,unsigned int *key)
// {
// 	unsigned int v0,v1;
// 	unsigned int t0,t1;
// 	unsigned long long int sum = 0x6E75316CULL*32;
	
// 	v0=*cipher;
// 	v1=cipher[1];
// 	t0=v0;
// 	t1=v1;
// 	for(int i=31;i>=0;i--)
// 	{
// 		v1-=((v0*16)+key[2])^(v0+sum)^((v0>>5)+key[3])^(sum+i);
// 		v0-=((v1*16)+*key)^(v1+sum)^((v1>>5)+key[1])^(sum+i);
// 		sum-=0x6E75316C;
// 	}
// 	*cipher=data1^v0;
// 	cipher[1]=data2^v1;
	
// 	data1=t0;
// 	data2=t1;
// }	

// int main()
// {
// 	unsigned int v[8];
// 	v[0]=0x9B28ED45;
// 	v[1]=0x145EC6E9;
// 	v[2]=0x5B27A6C3;
// 	v[3]=0xE59E75D5;
// 	v[4]=0xE82C2500;
// 	v[5]=0XA4211D92;
// 	v[6]=0xCD8A4B62;
// 	v[7]=0xA668F440;
// 	unsigned int k[4];
// 	k[0]=0x65766967;
// 	k[1]=0x756F795F;
// 	k[2]=0x7075635F;
// 	k[3]=0x6165745F;
	
// 	unsigned int lenth=sizeof(v);
	
// 	for(int p=0;p<8;p+=2)
// 	{

// 		unsigned int temp[2]={0};
// 		temp[1]=v[p+1];
// 		temp[0]=v[p];
// 		decrypto(temp,k);
// 		v[p] = temp[0];
// 		v[p+1] = temp[1];
// 		//decrypto(in+p,k);
// 	}
// 	unsigned char *word=(unsigned char *) v;
// 	for(int j=0;j<lenth;j++)
// 	{
// 		printf("%c",word[j]);
// 	}
// }
// //flag{133bffe401d223a02385d90c5f1ca377}


// //xtea

// #include<stdio.h>
// #include<stdint.h>
 
// void encipher(unsigned int num_rounds, uint32_t v[2], uint32_t const key[4]){
// 	unsigned int i;
// 	uint32_t v0=v[0],v1=v[1],sum=0,delta=0x9E3779B9;
// 	for(i=0;i<num_rounds;i++){
// 		v0+=(((v1<<4)^(v1>>5))+v1)^(sum+key[sum&3]);
// 		sum+=delta;
// 		v1+=(((v0<<4)^(v0>>5))+v0)^(sum+key[(sum>>11)&3]);
// 	}
// 	v[0]=v0;v[1]=v1;
// }
 
// void decipher(unsigned int num_rounds,uint32_t v[2],uint32_t const key[4]){
// 	unsigned int i;
// 	uint32_t v0=v[0],v1=v[1],delta=0x9E3779B9,sum=delta*num_rounds;
// 	for(i=0;i<num_rounds;i++){
// 	v1-=(((v0<<4)^(v0>>5))+v0)^(sum+key[(sum>>11)&3]);
// 	sum-=delta;
// 	v0-=(((v1<<4)^(v1>>5))+v1)^(sum+key[sum&3]);
// 	} 
// 	v[0]=v0;v[1]=v1;
// }
 
// int main(){
// 	uint32_t v[2]={1,2};
// 	uint32_t const k[4]={2,2,3,4};
// 	unsigned int r=32;				//这里是加密轮数，自己设置 
// 	printf("加密前原始数据：%u %u\n",v[0],v[1]);
// 	encipher(r,v,k);
// 	printf("加密后原始数据：%u %u\n",v[0],v[1]);
// 	decipher(r,v,k);
// 	printf("解密后原始数据：%u %u\n",v[0],v[1]);
// 	return 0;
// }


//xxtea
// #include <stdint.h>
 
// /* XXTEA加密算法的加密过程 */
// void xxtea_encrypt(uint32_t *v, int n, uint32_t *key) {
//     uint32_t y, z, sum, delta, e;
//     uint32_t p, rounds, limit;
//     uint32_t *k = key;
 
//     rounds = 6 + 52 / n;        // 计算加密轮数
//     sum = 0;
//     delta = 0x9E3779B9;         // 初始化delta常数
//     limit = rounds * delta;     // 计算sum的最大值
 
//     while (rounds-- > 0) {           // 执行加密轮数
//         sum += delta;           // 更新sum
//         e = sum >> 2 & 3;       // 计算e值
//         for (p = 0; p < n; p++) {   // 对每个数据块执行加密操作
//             y = v[(p + 1) % n];
//             z = v[p] += ((v[(p + n - 1) % n] >> 5) ^ (y << 2)) + ((y >> 3) ^ (v[(p + n - 1) % n] << 4)) ^ ((sum ^ y) + (k[(p ^ e) & 3] ^ v[(p + n - 1) % n]));
//             // 计算加密后的数据块
//         }
//     }
// }
 
// /* XXTEA加密算法的解密过程 */
// void xxtea_decrypt(uint32_t *v, int n, uint32_t *key) {
//     uint32_t y, z, sum, delta, e;
//     uint32_t p, q, rounds, limit;
//     uint32_t *k = key;
 
//     rounds = 6 + 52 / n;        // 计算加密轮数
//     sum = rounds * 0x9E3779B9;  // 初始化sum常数
//     delta = 0x9E3779B9;         // 初始化delta常数
//     limit = rounds * delta;     // 计算sum的最大值
 
//     q = 6 + limit / delta;
//     while (rounds-- > 0) {           // 执行加密轮数
//         e = sum >> 2 & 3;       // 计算e值
//         for (p = n - 1; p > 0; p--) {   // 对每个数据块执行解密操作
//             z = v[(p + n - 1) % n];
//             y = v[p] -= ((v[(p + n - 1) % n] >> 5) ^ (v[(p + 1) % n] << 2)) + ((v[(p + 1) % n] >> 3) ^ (v[(p + n - 1) % n] << 4)) ^ ((sum ^ v[(p + 1) % n]) + (k[(p ^ e) & 3] ^ v[(p + n - 1) % n]));
//             // 计算解密后的数据块
//         }
//         z = v[(n + n - 1) % n];
//         y = v[0] -= ((v[(n + n - 1) % n] >> 5) ^ (v[(1) % n] << 2)) + ((v[(1) % n] >> 3) ^ (v[(n + n - 1) % n] << 4)) ^ ((sum ^ v[(1) % n]) + (k[(0 ^ e) & 3] ^ v[(n + n - 1) % n]));
//         // 特殊处理第一个和最后一个数据块
//         sum -= delta;           // 更新sum
//     }
// }
 
