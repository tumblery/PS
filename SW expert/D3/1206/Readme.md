## Think
 각각의 건물의 view가 어떻게 되는지 고민을 해봐야하는데 음..... 각 건물의 왼쪽,오른쪽에서 제일 높은 건물의 층수를 현재 건물의 층수에서 빼주면 조망이 보장되는 층의 갯수를 알 수있을 듯하다.
 ```
 #define max(a,b) a>b?a:b
 int now//현재 건물의 위치
 int Rmax,Lmax,Max;
 Rmax = max(height[now+1],height[now+2]);//오른쪽에서 더 높은 건물의 길이
 Lmax = max(height[now-1],height[now-2]);//왼쪽에서 더 높은 건물의 길이
 Max = max(Rmax,Lmax);//건물 주변에서 가장 높은 건물의 층수
 if(Max < height[now])//만약 주변에서 가장 높은 건물보다 현재 건물이 더 높다면 조망권이 보장되는 층이 존재한다는 말이다.
 	view += (height[now]-Max);
 ```
 이런 식으로 각각의 층을 돌면서 조망권이 보장이 되는 층들을 알아 갈수 있을 듯 하다.