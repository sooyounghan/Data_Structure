-----
### Binary Heap
-----
1. Complete Binary Tree의 구조
2. 삽입과 삭제 시 트리를 우선 순위에 재배치하는 과정을 거침

-----
### Binary Heap의 특징
-----

<div align = "center">
<img width="640" alt="1" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/18524aa6-05b9-437c-a3b6-7ab17d493507">
</div>

1. 자식 보다 부모의 우선순위가 높음
2. Complete Binary Tree의 특징을 가지고 있음
3. 형제 간에는 우선순위는 존재하지 않음
4. 루트 노드는 우선순위가 가장 높은 데이터를 가지고 있음

-----
### Binary Heap의 삽입
-----
1. 노드는 항상 맨 마지막 Leaf 노드에 삽입
2. 삽입 후 부모의 우선순위와 비교
3. 삽입된 노드가 부모 노드보다 우선순위가 높을 경우, SWAP
4. 부모의 우선 순위보다 낮을 때까지 삽입된 노드를 상위로 올리는 것 : UpHeap

< 가장 값이 큰 것이 우선 순위가 높다고 가정 >

<div align = "center">
<img width="640" alt="2" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/824e8bda-b052-4d54-9702-0d7bd6ac762a">
</div>

1. 4 삽입 : 최초로 값이 삽입되면 루트 노드가 됨
2. 5 삽입 : 5가 부모(4) 보다 우선순위가 높으므로, 5를 위로 올리고, 4를 내림
3. 10 삽입 : 10이 부모(5)보다 우선순위가 높으므로, 10을 위로 올리고, 4를 내림

<div align = "center">
<img width="640" alt="3" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/1aba2c79-ea2f-4fee-a1eb-c34463f0d2a2">
</div>

4. 7 삽입 : 7이 부모 노드(5)보다 우선순위가 높으므로 7을 위로 올리고 5를 내림
5. 9 삽입 : 9가 부모 노드(7)보다 우선순위가 높으므로 9를 위로 올리고 7을 내림

<div align = "center">
<img width="640" alt="4" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/8aa48b1f-fb03-4d51-a698-df1ed685ebae">
</div>

6. 12 삽입 

       1. 12가 부모 노드(4)보다 우선 순위가 높으므로 12를 위로 올리고, 4를 내림
       2. 12가 부모 노드(10)보다 우선 순위가 높으므로 12를 위로 올리고, 10을 내림

<div align = "center">
<img width="640" alt="5" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/2745b130-f144-435a-813e-aeb8e3400cb1">
</div>   

7. 1 삽입 : 부모(10)보다 우선 순위가 낮으므로 아무런 연산을 하지 않음
8. 11 삽입 

        A. 부모(5)보다 우선 순위가 높으므로 11를 위로 올리고, 5를 내림
        B. 부모(9)보다 우선 순위가 높으므로 11를 위로 올리고, 9를 내림

<div align = "center">
<img width="640" alt="6" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/4f409ec5-69dd-4e72-a9f7-e50694e974bb">
</div>   

-----
### Binary Heap의 삭제
-----
1. 이진 힙(Binary Heap)은 루트 노드만 삭제 가능
2. 루트 노드를 삭제할 경우, 그 다음 우선순위가 높은 노드를 루트 노드로 변경
3. Heap의 구조를 유지하기 위해 부모의 노드가 자식 노드보다 우선 순위가 높을 때까지 아래로 내리는 것 : DownHeap

4. < 순서 >

        1. 루트 노드를 맨 마지막 Leaf 노드와 SWAP
        2. SWAP된 Leaf 노드를 삭제
        3. 새롭게 루트 노드가 된 노드를 자식 노드와 우선 순위를 비교하되, 자식 중에서 더 우선 순위가 높은 자식 노드와
           SWAP하고 자식 노드의 우선 순위가 낮을 때까지 SWAP(DownHeap)

< 가장 큰 값이 가진 노드가 우선 순위가 높다고 가정 >

<div align = "center">
<img width="640" alt="7" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/5cd1f4bc-6b88-46a4-ac64-4ea80c007b3c">
</div>    

1. 루트 노드(12)만 삭제할 수 있으므로, 루트 노드(12)와 맨 마지막 Leaf 노드(5)와 SWAP
   
<div align = "center">
<img width="640" alt="8" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/f30e8e70-07e3-4118-b497-2c3f35d3f034">
</div>   

2. 부모 노드(5)와 자식 중 더 우선 순위가 높은 노드는 11이므로 11을 위로 올리고 5를 내림
3. 부모 노드(5)와 자식 중 더 우선 순위가 높은 노드는 9이므로 9를 위로 올리고 5를 내림

   
<div align = "center">
<img width="640" alt="9" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/5587ce31-7c91-4d8d-a4f9-489deb8295ec">
</div>   

4. 루트 노드(11)만 삭제할 수 있으므로, 루트 노드(11)와 맨 마지막 Leaf 노드(1)와 SWAP

<div align = "center">
<img width="640" alt="10" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/7efd47e1-dfd9-4cd3-babb-02de493bb3af">
</div>   

5. 부모 노드(1)와 자식 중에서 더 우선 순위가 높은 노드는 10이므로 10을 위로 올리고, 1을 내림
6. 부모 노드(1)와 자식 중 더 우선 순위가 높은 노드는 4이므로 4를 위로 올리고, 1을 내림
7. 더 이상 자식이 없으므로 DownHeap은 종료
   
-----  
### Binary Heap의 삭제의 의미
-----
<div align = "center">
<img width="640" alt="11" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/89a8fb25-f317-4708-b102-f134dd4e16ed">
</div>   

1. Heap은 항상 우선 순위가 가장 높은 데이터를 꺼내거나 삭제하기 때문에 삽입 순서와 관련 없음
2. 이처럼 우선순위가 필요한 대기열이나 데이터 정렬이 필요할 때 사용 가능
