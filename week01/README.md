#week01

##Problem

+ Problem A: [NCTU OJ 10040](https://oj.nctu.me/groups/2/problems/10040/)
+ Problem B: [NCTU OJ 10041](https://oj.nctu.me/groups/2/problems/10041/)
+ Problem C: [NCTU OJ 10042](https://oj.nctu.me/groups/2/problems/10042/)
+ Problem D: [NCTU OJ 10043](https://oj.nctu.me/groups/2/problems/10043/)
+ Problem E: [NCTU OJ 10044](https://oj.nctu.me/groups/2/problems/10044/)

##Solution

###Problem A

顧名思義實作進位轉換~  
要注意的是輸入的測資有可能是10以上的進位制  
也就是說會有英文字母出現!!!  
記得做轉換  

###Problem B

題目就講出解法了XD  
對每一個數列求前綴和  
回答 a[r] - a[l-1]

###Problem C

加一加就AC了~

###Problem D

判斷方向後移動  
輸出最終位置

###Problem E

這題範圍到32-bit有號整數 = 2^32-1 = 2147483647  
+ 方法一  
  從2開始一個一個數字慢慢除看看...  
  如果沒有可以整除的數字就是質數  
  TLE...TLE...TLE...  
+ 方法二  
  可以預先建好 2^16 以下的質數  
  對於每個n判斷 sqrt(n) 以下的質數是否可以整除n
