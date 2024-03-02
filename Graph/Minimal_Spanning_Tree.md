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
<div align = "center">
<img width="1098" alt="7" src="https://github.com/sooyounghan/Web/assets/34672301/94d5d2e7-7e07-4365-9f45-358c8e6af794">
</div>

1. 그래프를 임의의로 절단한다고 했을 때, 가상의 두 그래프로 나뉠 수 있음
2. 절단을 교차하는 간선 중 안전 간선은 가중치가 1인 간선

<div align = "center">
<img width="1097" alt="8" src="https://github.com/sooyounghan/Web/assets/34672301/bf0dc0c8-7fa8-4529-8866-2eceb3b6d743">
</div>

3. 안전 간선을 A 간선 집합에 포함시킴
4. 그리고 A 집합은 아직 신장 트리를 만족하지 못하므로 신장 트리를 만족할 때까지, 게속 반복적으로 절단하는 과정 거침

<div align = "center">
<img width="1097" alt="9" src="https://github.com/sooyounghan/Web/assets/34672301/b8e42577-046d-4354-956f-af5caa3de71b">
</div>

5. 그래프를 임의로 절단했을 때, 안전 간선은 가중치가 2인 간선

<div align = "center">
<img width="1096" alt="10" src="https://github.com/sooyounghan/Web/assets/34672301/f3e50020-48ad-4447-8da6-4a5531b80bf6">
</div>

6. 완전 간선을 C 그래프에 포함시킴
7. 가상의 A 그래프와 C 그래프로 나누었으나, 알고리즘으로 보면 A라는 간선 집합에는 두 개의 트리 (A 그래프, C 그래프)가 존재하며 Forest 형성

<div align = "center">
<img width="1096" alt="11" src="https://github.com/sooyounghan/Web/assets/34672301/607fadd0-7f1c-43ba-a8e9-7d12c9c5523f">
</div>

8. 그래프를 임의로 절단했을 때 안전 간선은 가중치가 2인 간선

<div align = "center">
<img width="1097" alt="12" src="https://github.com/sooyounghan/Web/assets/34672301/fa50bf58-e48c-4866-aeb5-0ee67de2f0a2">
</div>

9. 안전 간선을 A 그래프에 포함

<div align = "center">
<img width="1097" alt="13" src="https://github.com/sooyounghan/Web/assets/34672301/9cda57a3-7505-4952-9299-8c5ce0bd28e4">
</div>

10. 그래프를 임의로 절단했을 때, 안전 간선은 가중치가 3인 간선

<div align = "center">
<img width="1098" alt="14" src="https://github.com/sooyounghan/Web/assets/34672301/725e0ca1-0eee-4497-8e04-5efc997229ca">
</div>

11. 안전 간선을 C 그래프에 포함 시킴

<div align = "center">
<img width="1097" alt="15" src="https://github.com/sooyounghan/Web/assets/34672301/281fd67f-9c22-4ddd-ab97-f7e10b886b45">
</div>

12. 그래프를 임의로 절단했을 때 안전 간선은 가중치가 3인 간선

<div align = "center">
<img width="1097" alt="16" src="https://github.com/sooyounghan/Web/assets/34672301/927e6556-aa3a-4c86-8f82-4a26e81cda18">
</div>

13. 안전 간선을 A 그래프에 포함

<div align = "center">
<img width="1098" alt="17" src="https://github.com/sooyounghan/Web/assets/34672301/33649c2f-df14-479e-b45d-76792e30656f">
</div>

14. 그래프를 절단했을 때, 안전 간선은 가중치가 3인 간선

<div align = "center">
<img width="1096" alt="18" src="https://github.com/sooyounghan/Web/assets/34672301/c71287b9-f0a5-4bca-8423-bbae4c4e9552">
</div>

15. 안전 간선을 A 그래프에포함시킴
16. A 집합에는 6개의 간선이 포함되며, 안전 간선만을 추가했으므로 최소 신장 트리
17. 해당 그림에서는 A 집합에 Forest를 형성하며 두 개의 트리로 존재하는 예시   
    (실제로는 여러 개의 트리로 집합에 포함될 수 있으며, 모든 간선이 연결되면 하나의 트리로 형성)
