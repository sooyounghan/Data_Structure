-----
### 트리 (Tree)
-----
<div align = "center">
<img width="640" alt="다운로드" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/174a90bd-aa9f-4d58-984a-092045fa0c72">
</div>

1. 유한한 노드들의 집합
2. 루트(Root)라는 특별한 노드 존재
3. 나머지 노드들은 n개의 서브트리로 분류

-----
### 트리의 특징
-----
1. 위에서 아래로 향하는 계층구조
2. 루트(Root) 노드를 가짐
3. 부모(Parent) 노드는 하나
4. 노드들끼리의 연결을 간선

-----
### 트리의 사용
-----
1. 특정한 키를 빠르게 찾기 위해 구조화하여 사용
2. 계층 구조를 표현 또는 순환 탐색 되지 않는 노드를 이용한 알고리즘


-----
### 노드(Node)와 키(Key)
-----
<div align = "center">
<img width="640" alt="다운로드 (1)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/1b87acc4-6a0a-486b-a236-923d60cf46e5">
</div>   
   : 트리 집합의 원소인 노드는 키 또는 값 또는 데이터라는 것을 가짐

-----
### 루트 노드 (Root Tree)
-----

<div align = "center">
<img width="640" alt="다운로드 (2)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/927928d3-1f61-47ac-8dde-8ee517cbd086">
</div>   

1. 최상위 노드
2. 모든 노드들은 루트 노드에서 시작
3. 루트 노드 아래 여러 후손(Descendent) 노드들이 존재

-----
### 서브 트리 (Subtree)와 차수 (Degree)
-----

<div align = "center">
<img width="640" alt="다운로드 (3)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/1ca5b749-21bc-48ab-acff-403363d44c2c">
</div>   
1. 서브 트리 (Subtree) : 특정 노드를 기준으로 아래에 있는 트리 / n개의 서브 트리로 분리

       A. 루트 노드를 기준으로 좌측 / 우측에 서브트리가 존재
       B. C 노드를 기준으로 좌측 / 중앙 / 우측에 서브 트리가 존재   

2. 차수 (Degree) : 특정 노드를 기준으로 서브 트리의 개수

       예) 루트 노드의 차수 : 2
           B 노드의 차수 : 2
           C 노드의 차수 : 3

-----
### 노드의 관계
-----
<div align = "center">
<img width="640" alt="다운로드 (4)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d87c6ad5-a8dc-40b2-a85a-e93d299efda2">
</div>   

- C 노드를 기준
 
      1. 루트 노드이며 부모 노드(Parent Node) : A 노드
         * 조상 노드(Ancestor Node) : C 노드 위에 있는 노드들
      2. 같은 부모를 가진 형제 노드(Slibing Node) : B 노드 
      3. 후손 노드(Descendant Node) : C 노드 아래에 있는 모든 노드들
      4. 간선으로 직접적으로 연결되어 있는 노드로 자식 노드(Child Node) : F, G, H 노드

- G 노드를 기준

      1. 루트 노드이며 부모 노드 : C 노드
      2. 같은 부모를 가진 형제 노드 : F, H 노드
      3. 자식 노드 : J, K 노드

-----
### 내부 노드(Internal Node)와 단말 노드(Leaf Node)
-----
<div align = "center">
<img width="640" alt="다운로드 (5)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/f5b49f78-445a-4092-bb53-9ff51a03f436">
</div>     

1. 단말(Terminal) / 잎사귀(Leaf) 노드 : 노드들 중 자식이 없는 노드 (차수가 0인 노드)
2. 비단말(Non-Terminal) / 내부(Internal) / 가지(Branch) 노드 : 부모도 존재하고, 자식도 존재하는 노드 (차수가 0이 아닌 노드)

-----
### Level / Height
-----
<div align = "center">
<img width="640" alt="다운로드 (6)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/3351b157-60bb-4ee2-810c-ad14a8293cf9">
</div>      

1. 레벨 : 루트를 Level 0으로 시작하여 특정 깊이를 가지는 집합 (Level 1로 루트를 시작하는 곳도 있음)

       - 루트의 자식 노드 (B, C)는 Leve 1
       - B, C의 노드 자식들은 Leve 2

2.  높이(Height) : 트리의 최대 Level (예제는 3)

-----
### Forest
-----
<div align = "center">
<img width="313" alt="다운로드 (7)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/bdbb28d4-53a3-4aa5-97ee-608aec174850">
</div>      
