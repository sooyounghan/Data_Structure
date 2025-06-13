-----
### 트리의 개념
-----
1. 선형 자료 구조는 선형으로 나열되어 있는 구조 (리스트, 스택, 큐 등)
<div align="center">
<img src="https://github.com/user-attachments/assets/5ef320ec-7a0a-49d1-9835-38fa380dab70">
</div>

2. 트리(Tree) : 계층적인 자료를 표현하는데 적합한 자료 구조
   - 실제 트리를 거꾸로 엎어놓은 것 같은 모양을 하고 있기 때문임
   - 인공 지능에서 결정 트리(Decision Tree) 등이 그 예시 (인간의 의사 결정 구조를 표현하는 한 가지 방법)

3. 트리의 용어
<div align="center">
<img src="https://github.com/user-attachments/assets/3925de51-b4eb-4f93-88c9-e80b7939f8b5">
</div>

   - 노드 (Node) : 트리의 구성 요소에 해당 (A, B, C, D, E, F, G, H, I, J)
   - 트리는 한 개 이상의 노드로 이루어진 유한 집합
   - 루트 노드(Root Node) : 계층적 구조에서 가장 높은 곳에 있는 노드 (A)
   - 서브 트리(Sub Tree) : 루트 노드를 제외하고 이루고 있는 트리 ({B, E, F, G}, {C, H}, {D, I, J} = 3개의 A의 서브트리로 구성)
     + {B, E, F, G} : 루트는 노드 B가 되며, 나머지 노드 들은 다시 3개의 서브트리 {E}, {F}, {G}로 나누어짐
     + {C, H}, {D, I, J}도 같은 식으로 루트와 서브 트리로 나누어짐

   - 트리에서 루트와 서브트리는 선으로 연결되는데, 이 연결선을 간선(Edge)
   - 노드들 간에는 부모 관계, 형제 관계, 조상과 자손 관계 존재
     + A는 B의 부모 노드 (Parent Node)
     + B는 A의 자식 노드 (Children Node)
     + B와 C와 D는 형제 관계 (Sibling)
   - 조상 노드 (Ancestor Node) : 루트 노드에서 임의의 노드까지 경로를 이루고 있는 노드
   - 후손 노드 (Descendent Node) : 임의의 노드 하위에 연결된 모든 노드들을 의미
     + 즉, 어떤 노드의 서브 트리에 속하는 모든 노드들은 후손 노드
   - 단말 노드 (Terminal Node 또는 Leaf Node) : 자식 노드가 없는 노드
   - 비단말 노드 (Non-TerminAL Node) : 자식 노드가 있느 노드

<div align="center">
<img src="https://github.com/user-attachments/assets/7643912b-f01e-4711-939c-5eb39e6dbcef">
</div>

   - 노드의 차수 (Degree) : 어떤 노드가 가지고 있는 자식 노드의 개수
     + 루트 노드의 경우, 자식 노드가 3개이므로, 차수도 3
     + 단말 노드의 경우, 차수가 0인 노드 ({E, F, G, H, I, J})
   - 트리의 차수 : 트리가 가지고 있는 노드의 차수 중 가장 큰 값
     + A와 B 노드의 차수가 3으로 가장 크므로, 전체 트리의 차수가 3
   - 트리의 레벨 (Level) : 트리의 각 층에 번호를 매기는 것으로, 루트 레벨은 1이 되고, 한 층 씩 내려갈수록 1씩 증가
     + A의 레벨은 1, B의 레벨은 2
   - 트리의 높이 (Height) : 트리가 가지고 있는 최대 레벨
     + 트리의 높이는 3
   - 포레스트 (Forest) : 트리들의 집합

<div align="center">
<img src="https://github.com/user-attachments/assets/546af898-b75c-4b35-9811-117aea9560f7">
</div>

4. 트리의 종류
   - 각 노드가 데이터를 저장하기 위한 데이터 필드와 노드를 가리키는 링크 필드를 가짐
<div align="center">
<img src="https://github.com/user-attachments/assets/edcbc397-9ddc-4e6d-8a0f-bef693d9ba0d">
</div>

   - n은 자식 노드의 개수, 즉 노드의 차수
   - 일반적인 트리에서 각 노드들은 서로 다른 개수의 자식 노드를 가지므로, 노드에 따라 링크 필드 개수가 달라짐
     + 문제점 : 노드의 크기가 고정되지 않으므로, 즉, 노드에 붙어 있는 자식 노드의 개수에 따라 노드의 크기가 커지기도 하고, 작아지기도 함
   - 이진 트리 (Binary Tree) : 자식 노드의 개수가 2개인 트리
