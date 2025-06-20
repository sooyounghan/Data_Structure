-----
### 큐 추상 데이터 타입
-----
1. 큐(Queue) : 먼저 들어온 데이터가 먼저 나가는 구조 (선입선출 (FIFO : First In First Out))
2. 큐는 뒤에서 새로운 데이터를 추가하고, 데이터가 하나씩 삭제되는 구조
   - 스택의 경우, 삽입과 삭제가 같은 쪽에서 일어나지만 큐에서는 삽입과 삭제가 다른 쪽에서 발생
   - 큐에서 삽입이 일어나는 곳 : 후단(Rear)
   - 큐에서 삭제가 일어나는 곳 : 전단(Front)
<div align="center">
<img src="https://github.com/user-attachments/assets/885c73ce-2cba-4ac5-9a06-0207375b15bc">
</div>

3. 큐의 추상 데이터 타입
<div align="center">
<img src="https://github.com/user-attachments/assets/d54c2132-e35f-4d0f-bf26-d99da648e479">
</div>

   - is_empty 연산 : 큐가 비어있으면 TRUE 반환, 그렇지 않으면 FALSE 반환
   - is_full 연산 : 큐가 가득차있으면 TRUE 반환, 그렇지 않으면 FALSE 반환
   - enqueue 연산 : 큐에 요소를 추가하는 연산으로, 큐의 맨 뒤에 새로운 요소 추가
   - dequeue 연산 : 큐의 맨 앞에 있는 요소를 꺼내어 외부로 반환
<div align="center">
<img src="https://github.com/user-attachments/assets/31b304fc-d704-4614-9bec-f4ea94495190">
</div>

  - 스택과 달리 삽입 및 삭제가 큐의 양끝에서 일어나므로 양단을 잘 확인해야 함

4. 큐는 삽입과 관련된 변수를 rear, 삭제와 관련된 변수를 front라 함
5. 큐의 이용 : 운영체제에서 중요하게 사용
   - 운영체제의 인쇄 작업 큐
     + 프린터는 속도가 늦고, 상대적으로 컴퓨터의 CPU 속도는 빠르므로 CPU는 빠른 속도로 인쇄 데이터를 만든 뒤, 인쇄 작업 큐에 저장하고 다음 작업으로 넘어감
     + 프린터는 인쇄 작업 큐에서 데이터를 가져다 인쇄
   - 키보드와 컴퓨터 사이에도 큐가 존재
     + 컴퓨터가 다른 작업을 하고 있더라도, 사용자가 키보드를 누르면 키 스트로크 데이터가 큐에 저장

6. 큐는 스택과 마찬가지로 배열과 연결리스트로 구현 가능
