-----
### Graph
-----

<div align = "center">
<img width="1097" alt="1" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/a995445e-4be8-40df-aa88-9a2ba04f16b1">
</div>   

1. 정점(Vertex)과 정점을 연결하는 간선(Edge)의 집합으로 구성된 자료구조
2. G = (V, E)으로 표기 : V는 정점의 집합, E는 간선의 집합
3. 정점 u는 정점의 집합에 속함 : (u ∈ V)
4. 간선 (u, v)는 간선의 집합에 속함 : (u, v ∈ E)

<div align = "center">
<img width="1098" alt="2" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/9879b6b3-32d5-4db2-95ee-b2c2db3618cb">
</div>   

-----
### 완전 그래프 (Complete Graph)
-----

<div align = "center">
<img width="1098" alt="3" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/e8cb81fb-ba41-4315-8f35-d4e92adfcba6">
</div>   

1. 모든 정점끼리 간선으로 연결되어 있는 것
2. 각 정점들은 모든 정점으로 연결되어 있는 간선을 가지고 있음
3. 하나라도 연결이 누락되어 있다면, 완전 그래프가 아님

-----
### 무방향 그래프
-----
<div align = "center">
<img width="1097" alt="5" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/5a119137-5afb-45ef-83d1-c6339d8534b7">
</div>     

1. 방향이 없는 간선을 가짐 (방향성이 없는 그래프)
2. 양방향으로 진행 가능
3. 무방향의 그래프의 간선은 (u1, v1), (u2, v2)로 표현

-----
### 방향 그래프
-----
<div align = "center">
<img width="1097" alt="6" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/9a54d7dd-101a-47f1-ba97-792653236fd6">
</div>   

1. 방향이 있는 간선을 가짐
2. 각 간선은 한 방향으로 진행 가능
3. 방향 그래프의 간선은 <u1, v1>, <u2, v2>으로 표현 가능

-----
### 정점의 차수 (Degree)
-----   

1. 정점에 접한 간선의 수

2. 무방향 그래프의 차수
<div align = "center">
<img width="1098" alt="7" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/ee8537e4-39d9-484e-a7f8-2222cca01a40">
</div>   

: 특정 정점을 기준으로 연결된 간선의 개수

2. 방향 그래프의 차수
<div align = "center">
<img width="1098" alt="8" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/67b503b3-989e-4b02-959c-446bcd284a9d">
</div>   

  - In-degree : 특정 정점을 기준으로 안으로 들어오는 방향의 간선의 개수
  - Out-degree : 특정 정점을 기준으로 밖으로 나가는 방향의 간선의 개수
  - Degree : In-degree + Out-degree

-----
### 경로 (Path)
-----    
<div align = "center">
<img width="1096" alt="9" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/8c17473e-5f96-46a3-a532-f57415003166">
</div>  

1. 정점 u로부터 정점 v까지의 정점의 순서열
2. 간선 (v1, v2), (v2, v3), (v3, v4)이 존재하면, v1, v2, v3을 말함

3. 단순 경로 (Simple Path)
<div align = "center">
<img width="1098" alt="10" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/8c6c4291-e4a9-42f2-baee-af867d30cf02">
</div>     

  - 한 경로상에 있는 모든 정점들이 서로 다르면 단순 경로 (Simple Path)
  - 다만, 단순 경로에서 처음과 마지막 정점은 동일할 수 있음
  - 예시) 2, 0, 1, 2 경로는 단순 경로이지만, 2, 0, 1, 2, 3은 단순 경로가 아님

4. 순환 (Cycle)
<div align = "center">
<img width="1098" alt="11" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/59d839f0-e7d5-43ef-8434-69ba7ae19c4d">
</div>    

  - 출발지와 도착지와 같은 단순 경로를 순환이라고 함
  - 예시) 경로 0, 1, 2, 0은 순환임

5. 가중치가 있는 그래프
<div align = "center">
<img width="1098" alt="12" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d2d24289-6e09-4ef3-bbaa-21c510bc906d">
</div> 


- 간선에 가중치가 있는 그래프
- 간선에 가중치가 존재하면, 특정 경로의 간선의 길이는 가중치의 합이 됨


-----
### 그래프와 트리의 정리
-----  
<div align = "center">
<img width="367" alt="13" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/c5e97a77-5db1-48fe-892e-ac72ec83f2c0">
</div> 


-----
### 현실 세계의 다양한 그래프
-----  

1. 친구 간의 친밀도  (정점은 친구들, 간선의 방향과 숫자는 사람의 호감도)
<div align = "center">
<img width="1098" alt="14" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/3b6a8a2b-0fb6-4933-bafe-4a3cbbea95a4">
</div> 

2. 친구 관계
<div align = "center">
<img width="1098" alt="15" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/f341a60a-5f85-4b6c-b722-71906adcb172">
</div> 

3. 도시 간의 이동과 경로
<div align = "center">
<img width="1097" alt="16" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/2569bf39-825a-4228-8a17-dce15f367639">
</div> 

4. 가계도 : 트리도 그래프 중 하나로 순환이 없는 그래프임
<div align = "center">
<img width="1098" alt="17" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/13be7105-0d12-4691-a524-e222a08c72da">
</div> 

6. 도시 간의 성장도
<div align = "center">
<img width="1098" alt="18" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/534c5f15-e04d-4639-8d8e-db753eb51ba6">
</div> 
