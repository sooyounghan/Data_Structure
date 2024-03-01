-----
### Spanning Tree
-----
<div align = "center">
<img width="1097" alt="1" src="https://github.com/sooyounghan/Web/assets/34672301/220665f0-989f-4a76-b21e-d68b9db520bb">
</div>

: 신장 트리란 순환(Cycle) 없이 모든 정점을 연결하는 그래프

-----
### Minimum Spanning Tree
-----
<div align = "center">
<img width="1097" alt="2" src="https://github.com/sooyounghan/Web/assets/34672301/5750e45d-9ddd-4898-9096-2e83b6c62bd8">
</div>

: 모든 정점을 순환(Cyle) 없이, 최소 간선 비용으로 모든 정점을 연결하는 그래프

-----
### 절단 (Cut)
-----
<div align = "center">
<img width="1097" alt="3" src="https://github.com/sooyounghan/Web/assets/34672301/ac4ebd00-db51-4227-ad63-3b90de0d6a6a">
</div>

1. 그래프 G = (V, E)를 절단하는 것을 의미
2. 그래프를 절단 (S, V-S)하면, 임의의 S라는 정점의 집합과 V-S라는 정점의 집합으로 분리

-----
### 교차 (Cross)
-----
<div align = "center">
<img width="1098" alt="4" src="https://github.com/sooyounghan/Web/assets/34672301/b6f2dd81-24f3-4288-a1ab-d871786244b7">
</div>

: S의 정점과 V-S의 정점을 연결하는 간선이 존재한다면, 해당 간선을 교차(Cross)한다고 함

-----
### 존중 (Respect)
-----
<div align = "center">
<img width="1097" alt="5" src="https://github.com/sooyounghan/Web/assets/34672301/fed5182b-b6cc-473f-b3aa-1b0d87c29ac6">
</div>

: A를 그래프의 최소 신장 트리에 포함되는 간선의 부분집합이라 하면, A에 절단을 교차하는 간선이 존재하지 않는다면 절단은 A를 존중(Respect)한다라고 함

-----
### 경량 간선 (Light Edge)
-----
<div align = "center">
<img width="1098" alt="6" src="https://github.com/sooyounghan/Web/assets/34672301/d7ea94c5-97eb-415b-82d2-63240758adc8">
</div>

: 절단을 교차하는 간선 중 가중치가 최소인 간선

-----
### 안전 간선 (Safe Edge)
-----
1. 최소 신장 트리를 만족하며, 루프 불변성을 유지하기 위해 경량 간선이어야 함
2. 그래프를 순환하지 않도록 하는 간선

       <루프 불변성>
        - 여러 번 반복하더라도 성질에 대해 불변성을 만족하는 것
        - 초기조건, 유지조건, 종료조건이 있으며, 여러번 반복하더라도 성질에 대해 불변성을 만족해야함
        - 루프가 종료되더라도 기본 성질은 변하지 않음

-----
### 최소 신장 트리의 일반 알고리즘
-----
```java
GENERIC_MST(G, w) {
    A = 공집합
    while A가 신장 트리를 형성하지 못한다
       A에 대한 안전 간선(u, v)를 찾는다
       A = A ∪ {(u, v)}
    return A;
}
```
1. 여러 번 반복하더라도 A의 집합이 최소 신장 트리를 만족하도록 하는 루프 불변성을 가짐
2. 항상 A 집합에 안전 간선만을 추가하므로 루프의 중간에 A 집합을 확인하더라도 최소 신장 트리 만족
   
-----
### 최소 신장 트리 일반 알고리즘
-----
