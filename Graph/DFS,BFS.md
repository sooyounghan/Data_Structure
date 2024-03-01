-----
### 깊이 우선 탐색 (DFS)
-----
<1번 정점부터 순회하면서, 작은 번호를 가진 정점 순서대로 방문하다고 가정>

<div align = "center">
<img width="1099" alt="1" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/f56b7c6d-036c-415f-b066-0ddf946d51c8">
</div>

<div align = "center">
<img width="1098" alt="2" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/a7ff4eeb-5431-4582-87c1-050f29bbae8a">
</div>

1. 1번 정점을 먼저 방문하여 방문 처리

<div align = "center">
<img width="1097" alt="3" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/8c165006-861b-48e0-a75f-3deed99041c8">
</div>   

2. 1번 정점과 인접한 정점 중 가장 작은 번호인 0번 정점 먼저 방문 후 방문 처리


<div align = "center">
<img width="1098" alt="4" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/991dd398-8d31-444b-a63d-55d0c0a7a050">
</div>

3. 0번 정점과 인접한 정점 중 방문하지 않았으면서 가장 작은 번호인 2번 정점 방문 하고 방문 처리

<div align = "center">
<img width="1098" alt="5" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/cdf309b9-c2eb-4a2f-8dcc-197189933828"> 
</div>


4. 2번 정점과 인접한 정점 중 방문하지 않았으면서 가장 작은 번호를 가진 3번 정점을 방문하고 방문 처리

<div align = "center">
<img width="1098" alt="6" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/19a114eb-d8df-4608-a29f-087654bfc2c5">
</div>

5. 3번 정점과 인접한 정점 중 방문하지 않았으면서 가장 작은 번호를 가지고 있는 4번 정점 방문 후 방문처리

<div align = "center">
<img width="1097" alt="7" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d1a74ede-3796-4032-9842-4546ce3cde41">
</div>

6. 4번 정점과 인접한 정점 중 방문하지 않았으면서 가장 작은 번호를 가지고 있는 5번 정점 방문 후 방문처리
7. 5번 정점까지 방문하면 이전 분기로 돌아가는 방식으로 깊이 우선 탐색 종료

-----
### 너비 우선 탐색 (BFS)
-----
<1번 정점부터 순회하면서 가장 작은 번호를 가진 정점 순서대로 방문한다고 가정>   

<div align = "center">
<img width="1098" alt="8" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/bd1b1d5f-57e9-4bd6-ba1d-e974ae728fc2">
</div>

<div align = "center">
<img width="1097" alt="9" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d2be1839-9024-4831-8c59-7893954fed19">
</div>  

1. 1번 정점을 큐에 저장하고 방문하고 방문 처리

<div align = "center">
<img width="1097" alt="10" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/5bca4e48-45c9-4c1a-ada1-a43f5ecc04a0">
</div>

2. 1번 정점을 큐에서 꺼냄

<div align = "center">
<img width="1097" alt="11" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/fd00402c-d458-4af9-9d98-f398d4987dc6">
</div>

3. 1번 정점 기준 인접한 정점 중 가장 작은 번호를 가진 0번 정점을 큐에 저장 후 방문 처리

<div align = "center">
<img width="1097" alt="12" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/b749db82-c2ed-4363-9e34-bf5657ff33c0">
</div>

4. 1번 정점 기준 인접한 정점 중 그 다음 작은 번호를 가진 3번 정점을 큐에 저장하고 방문 후 방문 처리

<div align = "center">
<img width="1098" alt="13" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/2b9c3b4c-0c62-4fd7-887c-d0bfba28abc1">
</div>

5. 1번 정점 기준 인접한 정점 중 그 다음 작은 번호를 가진 4번 정점을 큐에 저장하고 방문 후 방문 처리

<div align = "center">
<img width="1097" alt="14" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/e8db27ac-de45-4ae4-baf5-f80dd7719e28">
</div>

6. 0번 정점을 큐에서 꺼냄

<div align = "center">
<img width="1097" alt="15" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/36d56c8c-3f3b-48e0-baa2-f50cea0fc236">
</div>

7. 0번 정점 기준 인접한 정점 중 방문하지 않았으면서 가장 작은 번호를 가진 2번 정점을 큐에 저장하고 방문 처리

<div align = "center">
<img width="1097" alt="16" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d64fcf4a-aa3a-4c4b-9a3a-6a6ee54c49fb">
</div>

8. 3번 정점을 큐에서 꺼낸 후, 3번 정점 기준 가장 인접한 정점 중 방문하지 않은 정점이 없으므로 넘어감

<div align = "center">
<img width="1098" alt="17" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/8581f882-1b1c-4810-a8cb-975070c19cc9">
</div>

9. 4번 정점을 큐에서 꺼냄

<div align = "center">
<img width="1097" alt="18" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/64b121a4-6d07-4da0-8f24-275cc6d28d33">
</div>

10. 2번 정점을 꺼낸 후, 2번 정점 기준 인접한 정점 중 방문하지 않은 정점이 없으므로 넘어감

<div align = "center">
<img width="1097" alt="18" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/64b121a4-6d07-4da0-8f24-275cc6d28d33">
</div>

11. 4번 정점 기준 인접한 정점 중 작은 번호를 가진 5번 정점을 큐에 넣고 저장 후 방문 처리

<div align = "center">
<img width="1097" alt="19" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/f4c7eea1-d50f-4e9a-8687-927f61a0c2c8">
</div>

12. 2번 정점을 큐에서 꺼낸 후, 2번 정점 기준 인접한 정점 중 방문하지 않은 정점이 없으므로 넘어감

<div align = "center">
<img width="1098" alt="20" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/3b414712-34c9-4877-9a13-5d47977ff8be">
</div>

13. 5번 정점을 큐에서 꺼낸 후, 5번 정점 기준 인접한 정점 중 방문하지 않은 정점이 없으므로 넘어감

14. 큐에 모든 정점을 꺼내면 너비 우선 탐색 종료 
