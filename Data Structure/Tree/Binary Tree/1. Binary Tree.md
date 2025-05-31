-----
### 이진 트리 (Binary Tree)
-----
1. 트리에서 가장 많이 사용하는 트리로서, 모든 노드가 2개의 서브 트리를 가지고 있는 트리
<div align="center">
<img src="https://github.com/user-attachments/assets/36e10b29-7bc3-40ff-9a91-0666cd75fd7b">
</div>

2. 💡 서브 트리는 공집합일 수 있거나, 이진트리의 노드에는 최대 2개까지의 자식 노드가 존재할 수 있고, 모든 노드의 차수가 2 이하이어야 함
   - 공집합도 이진트리
   - 또한, 이진 트리에는 서브 트리간 순서가 존재하여, 왼쪽 서브 트리와 오른쪽 서브트리는 서로 구별
3. 💡 루트와 왼쪽 서브 트리, 오른쪽 서브 트리로 구성된 노드들의 유한 집합으로 정의 되며, 이진트리의 서브 트리들은 모두 이진트리어야함
4. 이진 트리는 순환적으로 정의되고 있음
5. 즉, 이진 트리의 서브트리도 이진 트리의 성질을 만족해야 함
6. 이진 트리 검증 예시
<div align="center">
<img src="https://github.com/user-attachments/assets/19a50b40-cf17-4b5c-ad31-052560af259c">
</div>

  - 밑에서부터 위로 올라가면서 확인
  - SUB3 : 하나의 노드 D로만 구성
    + 만약 노드 D가 SUB3의 루트라고 생각하면 SUB3의 서브 트리는 공집합 (이진트리도 공집합)
    + 따라서, SUB3는 루트와 공집합 서브 트리 2개를 가지는 이진트리

  - SUB2도 루트와 공집합 서브 트리를 가지고 있으므로 이진 트리
  - SUB1은 SUB1의 루트 노드 B와 서브 트리 SUB3의 공집합 서브 트리를 가지고 있으므로, 이진트리
  - 최종적으로 전체 트리는 루트 노드 A와 SUB1, SUB2의 두 개의 서브 트리를 가지는데, 이 두 개의 서브 트리가 이진트리이므로, 전체 트리도 이진트리

7. 이진 트리와 일반 트리의 차이점
   - 이진 트리의 모든 노드는 차수가 2 이하(자식 노드의 개수가 2개 이하)지만, 일반 트리는 자식 노드의 개수 제한이 없음
   - 일반 트리와 다르게 이진 트리는 노드를 하나도 갖지 않을 수 있음
   - 서브 트리 간 순서가 존재한다는 점 = 왼쪽 서브 트리와 오른쪽 서브 트리를 이진 트리는 구분

8. 이진 트리의 예 - 수식 표현
<div align="center">
<img src="https://github.com/user-attachments/assets/137f7032-a3de-4694-8ca8-15dc50e40e40">
</div>

   - 수식에서 각 연산자들은 하나 또는 2개의 피연산자들을 가짐
   - 왼쪽 피 연산자는 왼쪽 서브트리가 되고, 오른쪽 피 연산자는 오른쪽 서브 트리로 표현
   - 단말노드는 상수 또는 변수

-----
### 이진 트리의 성질
-----
1. $n$개의 노드를 가지는 이진 트리는 정확하게 $n - 1$개의 간선을 가짐
   - 이진트리에서의 노드는 루트를 제외하면, 하나의 부모 노드를 가짐
   - 부모와 자식 간에는 정확하게 하나의 간선만이 존재
   - 따라서 간선의 개수는 $n - 1$
<div align="center">
<img src="https://github.com/user-attachments/assets/381cd6aa-cfb7-4fec-9f80-761e358251f5">
</div>

2. 높이가 $h$인 이진 트리의 경우, 최소 $h$개의 노드를 가지며, 최대 $2^k - 1$개의 노드를 가짐
   - 한 레벨에는 적어도 하나의 노드가 존재해야 하므로, 높이가 $h$인 이진 트리에서 적어도 $h$개의 노드를 가짐
   - 하나의 노드는 최대 2개의 자식을 가질 수 있으므로, 레벨 $i$에서의 최대 노드의 개수는 $2^{i - 1}$
   - 따라서, 전체 노드의 개수는 $\sum_{i=1}^{k} 2^{i-1}$ = $2^k - 1$
     + 참고 : 등비 수열의 합 $S_n = a \cdot \frac{r^n - 1}{r - 1} \quad \text{단, } r \ne 1$
<div align="center">
<img src="https://github.com/user-attachments/assets/be2197e5-48aa-4a29-aedb-a2c88d5833fa">
</div>

3. $n$개의 노드를 가지는 이진 트리의 최대 높이는 최대 $n$이거나 최소 $\left\lfloor \log_2(n+1) \right\rfloor$
   - 레벨 당 최소한 하나의 노드가 있어야 하므로 높이 n을 넘을 수 없음
   - 높이 $h$인 이진 트리가 가질 수 있는 노드의 최댓값은 $2^h - 1$
     + 따라서, $n \leq 2^h - 1$의 부등식이 성립
     + 양변에 $log$를 취하여 정리하면, $h \geq log_2(n+1)$
     + $h$는 정수이어야 하므로 $h \geq \left\lfloor log_2(n+1) \right\rfloor$ ([ ... ] : 올림 연산)
<div align="center">
<img src="https://github.com/user-attachments/assets/0124c58d-bd1e-45fe-81b1-25308c1be0f7">
</div>

-----
### 이진 트리의 성질
-----
1. 형태에 따라 분류
   - 포화 이진 트리 (Full Binary Tree)
   - 완전 이진 트리 (Complete Binary Tree)
   - 기타 이진 트리

<div align="center">
<img src="https://github.com/user-attachments/assets/0368c071-353b-4bf0-9172-1de81d6b9ef8">
</div>

2. 포화 이진 트리 (Full Binary Tree) : 트리의 각 레벨에 노드가 꽉 차 있는 이진 트리
   - 즉, 높이 $k$인 포화 이진 트리는 정확하게 $2^k - 1$개의 노드를 가짐
   - 높이가 4인 이진트리
<div align="center">
<img src="https://github.com/user-attachments/assets/cdce5584-5a41-432f-84bc-c777d4a427ee">
</div>

   - 각 노드에 번호를 붙일 수 있음
   - 노드에 번호를 부여하는 방법은 레벨 단위로 왼쪽에서 오른쪽으로 번호를 붙이면 되며, 이 번호는 항상 일정
     + 즉, 루트 노드의 오른쪽 자식 노드 번호는 항상 3
<div align="center">
<img src="https://github.com/user-attachments/assets/adb5df33-78e4-4196-9f82-34ddb96037d3">
</div>

3. 💡 완전 이진 트리 (Complete Binary Tree) : 높이가 $k$일 때, 레벨 1부터 $k - 1$까지는 노드가 모두 채워져있고, 마지막 레벨 $k$에서는 왼쪽부터 오른쪽으로 노드가 순서대로 채워져 있는 이진 트리
   - 💡 마지막 레벨에서는 노드가 꽉 차 있지 않아도 되지만, 중간에 빈 곳이 있어서는 안 됨
   - 💡 따라서, 포화 이진 트리는 항상 완전 이진 트리이지만, 그 역은 성립하지 않음
   - 포화 이진 트리의 노드 번호와 완전 이진 트리의 노드 번호는 1 : 1 대음

<div align="center">
<img src="https://github.com/user-attachments/assets/7021a27a-910c-4234-a0ae-fd28d8a1c76b">
</div>
