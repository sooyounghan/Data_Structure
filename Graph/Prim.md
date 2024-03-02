-----
### Minimal Spanning Tree - Prim
-----
1. BFS와 같이 정점 방문 후 정점을 기준으로 부속된 간선들을 우선순위 큐에 가중치 순으로 저장
2. 큐에서 간선을 꺼내, 방문하지 않은 정점들을 방문하여 안전 간선을 추가하는 알고리즘
3. Kruskal 알고리즘이 안전 간선 집합이 Forest 형성하면, Prim 알고리즘은 하나의 최소 신장 트리를 유지

```java
 PRIM_MST() {
    vertex = 방문할 정점
    priorityQueue;
    while 방문하지 않은 정점이 존재한다
        visit(vertex)
        for 정점에 부속된 간선을 priorityQueue에 저장한다
            if 간선의 정점을 방문하지 않았다
                간선을 priorityQueue에 저장한다

        while priorityQueue에 간선이 존재한다
            edge = 큐에서 꺼낸 간선
            if 간선의 정점을 방문하지 않았다
                vertex = 간선의 도착지 정점
                해당 간선을 안전 간선으로 추가한다
                break;
}
```

-----
### Minimal Spanning Tree - Prim 예제
-----

<div align = "center">
<img width="1099" alt="1" src="https://github.com/sooyounghan/Web/assets/34672301/2cf2e9fb-e743-4b6d-a721-dbc6992fb3ce">
</div>
1. 아래와 같은 그래프가 있다고 가정하고, 방문 여부를 체크하는 배열과, 간선의 가정치 순대로 저장하는 우선 순위 큐 준비

<div align = "center">
<img width="1096" alt="2" src="https://github.com/sooyounghan/Web/assets/34672301/6cc6a8a7-a0d8-45b4-80c3-7eda5e93d0e7">
</div>

2. 최초의 탐색 정점을 0으로 가정하고 방문 처리

<div align = "center">
<img width="1098" alt="3" src="https://github.com/sooyounghan/Web/assets/34672301/7d86f767-505c-4da8-a81c-099efd0e9889">
</div>

3. 0번 정점을 기준으로 부속된 간선들 중 도착지 기준 아직 방문하지 않은 간선을 우선순위 큐에 저장

<div align = "center">
<img width="1097" alt="4" src="https://github.com/sooyounghan/Web/assets/34672301/2b677303-c705-4016-9089-895e0bbd8c07">
</div>

4. 우선순위 큐에서 간선 하나를 꺼내서 도착지 기준 방문하지 않은 정점이면, 해당 간선을 안전 간선에 추가
5. 다음 방문할 정점인 2번 정점을 저장

<div align = "center">
<img width="1099" alt="5" src="https://github.com/sooyounghan/Web/assets/34672301/eb3479a2-d6a0-43af-9eda-b90b2497c09a">
</div>

6. 2번 정점을 방문 처리

<div align = "center">
<img width="1099" alt="6" src="https://github.com/sooyounghan/Web/assets/34672301/da04c6bf-fdea-48b7-bd8a-89ac692dacb0">
</div>

7. 2번 정점을 기준으로 부속된 간선들 중 아직 도착 기준 방문하지 않은 간선을 우선순위 큐에 저장

<div align = "center">
<img width="1097" alt="7" src="https://github.com/sooyounghan/Web/assets/34672301/cc31abaf-ce00-4779-a2a3-5c48a230f3ba">
</div>

8. 우선순위 큐에서 간선 하나를 꺼내서 도착지 기준 아직 방문하지 않은 정점이면 해당 간선을 안전 간선으로 추가
9. 다음에 방문할 정점인 1번 정점을 저장
   
<div align = "center">
<img width="1098" alt="8" src="https://github.com/sooyounghan/Web/assets/34672301/e7cd12ee-7e75-4d68-b7c5-93bb13ca4f52">
</div>

10. 1번 정점을 방문 처리

<div align = "center">
<img width="1098" alt="9" src="https://github.com/sooyounghan/Web/assets/34672301/d6bfba0a-3189-4fe5-8e47-ed8faa3eaf86">
</div>

11. 1번 정점 기준 부속된 간선들 중 아직 도착지 기준 방문하지 않은 간선을 우선순위 큐에 저장

<div align = "center">
<img width="1098" alt="10" src="https://github.com/sooyounghan/Web/assets/34672301/84d46ece-9f29-45ac-ac6e-93efc8170ebc">
</div>

12. 우선순위 큐에서 간선 하나를 꺼내고, 도착지 기준 아직 방문하지 않은 정점이면 해당 간선을 안전 간선에 추가
13. 다음 방문할 정점인 3번 정점을 저장

<div align = "center">
<img width="1098" alt="11" src="https://github.com/sooyounghan/Web/assets/34672301/b42be1e8-a31c-4d0c-a5f4-e6ea1ea4318f">
</div>

14. 3번 정점을 방문 처리

<div align = "center">
<img width="1098" alt="12" src="https://github.com/sooyounghan/Web/assets/34672301/8ced62ed-c101-4440-baa4-262743bdf1d4">
</div>

15. 3번 정점 기준 부속된 간선들 중 도착지 기준 아직 방문하지 않은 간선을 우선순위 큐에 저장

<div align = "center">
<img width="1098" alt="13" src="https://github.com/sooyounghan/Web/assets/34672301/a82f6d55-868a-4d25-bae6-0127f79d4886">
</div>

16. 우선순위 큐에서 간선 하나를 꺼내서 확인하지만, 도착지 기준 이미 방문했던 정점이므로 해당 간선을 패스
    
<div align = "center">
<img width="1097" alt="14" src="https://github.com/sooyounghan/Web/assets/34672301/c24d68b8-2608-4403-9101-ce3b05a114f9">
</div>

17. 우선순위 큐에서 간선 하나를 꺼내서 도착지 기준 아직 방문하지 않은 정점이므로 해당 간선을 안전 간선으로 추가
18. 다음에 방문할 정점으로 4번 정점을 저장

<div align = "center">
<img width="1096" alt="15" src="https://github.com/sooyounghan/Web/assets/34672301/cc08e5b3-da5a-4399-9fae-abb83a95452f">
</div>

19. 4번 정점을 방문 처리

<div align = "center">
<img width="1096" alt="16" src="https://github.com/sooyounghan/Web/assets/34672301/ffbf807b-ed8f-4802-903e-8251dbcd6c05">
</div>

20. 4번 정점 기준 부속된 간선들 중 도착지 기준 아직 방문하지 않은 간선을 우선순위 큐에 저장

<div align = "center">
<img width="1097" alt="17" src="https://github.com/sooyounghan/Web/assets/34672301/add392b4-f751-49f5-b742-8fa4d5d81e8d">
</div>

21. 우선순위 큐에서 간선 하나를 꺼내서 확인하면 도착지 기준 아직 방문하지 않은 정점이므로 해당 간선을 안전 간선에 추가
22. 다음에 방문할 정점으로 5번 정점을 지정

<div align = "center">
<img width="1097" alt="18" src="https://github.com/sooyounghan/Web/assets/34672301/78a9e884-50b8-405d-9b98-c6984c2076ef">
</div>

23. 5번 정점을 방문 처리

<div align = "center">
<img width="1097" alt="19" src="https://github.com/sooyounghan/Web/assets/34672301/dca9be04-6444-481c-8a6c-e6e0a06616de">
</div>

24. 5번 정점 기준 부속된 간선들 중 도착지 기준 아직 방문하지 않은 간선을 우선 순위 큐에 저장

<div align = "center">
<img width="1096" alt="20" src="https://github.com/sooyounghan/Web/assets/34672301/ebef9e49-fed0-487a-9ad3-24d7a702cf5d">
</div>

25. 우선순위 큐에서 간선을 하나 꺼낸 후 확인하면 도착지 기준 방문하지 않은 정점이므로 해당 간선을 안전 간선에 추가
26. 다음 방문할 정점으로 6번 정점을 저장

<div align = "center">
<img width="1098" alt="21" src="https://github.com/sooyounghan/Web/assets/34672301/2ea5aaae-a830-42c9-a6c3-46314266bb47">
</div>

27. 6번 정점을 방문

<div align = "center">
<img width="1097" alt="22" src="https://github.com/sooyounghan/Web/assets/34672301/5f45d808-5958-4dc4-936d-915434e6a56b">
</div>

28. 6번 정점 기준 부속된 간선들 중 도착지 기준 방문하지 않은 간선이 존재하지 않으므로 패스
29. 우선순위 큐에서 간선 하나를 꺼내서 확인하지만 도착지 기준 이미 방문했던 정점으로 해당 간선은 패스

<div align = "center">
<img width="1097" alt="23" src="https://github.com/sooyounghan/Web/assets/34672301/e3a35edb-ddd8-4a60-947b-41f68d1b02d4">
</div>

30. 우선순위 큐에서 간선 하나를 꺼내 확인하지만, 도착지 기준 이미 방문했던 정점이므로 해당 간선을 패스

<div align = "center">
<img width="1097" alt="24" src="https://github.com/sooyounghan/Web/assets/34672301/1d0096e8-6090-48ea-a99c-7f39ed884254"></div>

31. 우선순위 큐에서 간선 하나를 꺼내 확인하지만, 도착지 기준 이미 방문했던 정점이므로 해당 간선을 패스
 
<div align = "center">
<img width="1098" alt="25" src="https://github.com/sooyounghan/Web/assets/34672301/b2009f92-c282-46a4-8bb7-398b9e334a2e">
</div>

32. 우선순위 큐에서 간선 하나를 꺼내 확인하지만, 도착지 기준 이미 방문했던 정점이므로 해당 간선을 패스

<div align = "center">
<img width="1096" alt="26" src="https://github.com/sooyounghan/Web/assets/34672301/38458339-d7b2-40ac-b471-5ae339a14ac9">
</div>

33. 우선순위 큐에서 간선 하나를 꺼내 확인하지만, 도착지 기준 이미 방문했던 정점이므로 해당 간선을 패스

34. Frim 알고리즘은 정점 방문 시 부속된 간선들을 가중치 우선순위 큐에 저장하고, 우선순위가 높은 순으로 간선을 하나씩 꺼냄
    - 방문 여부를 판단한 뒤, 방문하지 않았으면 안전 간선으로 추가하고, 다음에 방문할 정점을 정하는 방식
    - 안전 간선을 유지하면서, 최소 신장 트리를 만듬
