-----
### 단일 연결리스트(Singly Linked List)
-----
1. 연결리스트(Linked List) : 각 노드가 데이터와 포인터를 가지고 한 줄로 연결되어 있는 방식으로 데이터를 저장하는 구조
2. 단일 연결리스트에서는 데이터와 다음 노드의 참조값을 가지고 있음

       * Node : 일반적으로 리스트, 그래프, 트리 이론에서 데이터 구조를 구성하는 각각의 객체를 의미
                (서로 간의 연결될 수도 있고, 연결되지 않을 수도 있음)

       * 연결 : 각 노드끼리 접근할 수 있는 참조값을 저장하여 노드에서 다음 노드에 접근할 수 있는 것
<div align = "center">
<img src = "https://github.com/sooyounghan/Data-Structure/assets/34672301/c5ad6bc6-c846-446b-b4c7-f6d48d179d45">
</div>

3. 특징
      
        A. Node는 항상 앞의 Node의 참조값만 알 수 있음
        B. 중간 노드가 제거 되면, 그 다음의 연결되는 노드를 찾을 수 없음
           따라서, 노드가 제거되기 전에, 그 다음 연결되는 노드의 참조값을 미리 유지해야함
        C. 노드 간의 선형적으로 연결되어 있으므로, 순차적으로 탐색해야함

-----
### 단일 연결리스트(Singly Linked List)의 구성
-----
1. Head : 가장 첫 번째 노드의 참조값을 가리키는 가지는 변수나 노드 (노드가 없다면 null값을 지님)
2. 가장 마지막 노드는 다음 노드의 참조값으로 null을 가짐


<div align = "center">
<img src = "https://github.com/sooyounghan/Data-Structure/assets/34672301/e6bad991-7544-4479-a2dd-75c8d2b8c66e">
</div>

-----
### 단일 연결리스트(Singly Linked List)의 장점
-----
1. 저장하는 데이터의 개수가 예측 불가능할 때 사용 가능
2. 필요한 만큼의 메모리를 사용하기 때문에 배열보다 상대적 메모리 절약 가능
3. 데이터 삭제/삽입이 배열보다 더 간단하고 빠름 (배열 : 중간 데이터 삭제의 경우 재배치 필요)

-----
### 단일 연결리스트(Singly Linked List)의 단점
-----
1. 하나의 연결만을 가지므로 노드를 앞에서부터 순차적으로 찾음 (인덱스를 계산하는 방식으로 접근하는 배열보다 탐색 속도가 느림)
2. Pointer는 항상 head부터 시작해야하므로, 노드 간 잘못 연결 시 다음 노드를 영원히 찾을 수 없음

-----
### 배열과 단일 연결리스트(Singly Linked List)의 시간 복잡도
-----
<div align = "center">
<img width="310" alt="e" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/a485e4da-ef61-4376-a760-2af6f20c6fad">
</div>


-----
### 단일 연결리스트(Singly Linked List)의 삽입
-----
1. 맨 앞에 Node를 삽입할 때
<div align = "center">
<img width="1097" alt="5" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/3cc46817-0b5f-4687-9e94-bfaf1be8655b">
</div>

  - 맨 앞에 노드를 삽입할 때에는 pointer는 먼저 head에 접근 후, 새로운 노드를 생성
  - head가 가리키는 노드의 참조 값을 새로운 노드의 참조값으로 저장 (head와 새로운 노드의 참조값은 다음 노드의 참조값을 서로 가리킴)
  - 마지막으로 head는 새로운 노드의 참조값을 저장
    
2. 중간에 Node를 삽입 할 때

<div align = "center">
<img width="1098" alt="6" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/31eca9ec-92d5-481e-8377-6ea62093048d">
</div>

  - 노드를 중간에 삽입할 때에는 노드와 노드 사이의 연결이 끊어지지 않도록, 즉 참조값이 분실되지 않도록 해야함
  - 삽입하려는 위치 이전의 노드를 NodeB라고 하면, NodeB에 pointer를 접근
  - 이전 노드(NodeB)를 통해 다음 노드(NodeC)의 참조값을 알아야 함
  - 다음 노드(NodeC)의 참조값을 새롭게 생성된 노드의 다음 노드의 참조값으로 저장
  - 새로운 노드의 다음 노드는 NodeC를 가리킴 (이 때, NodeB와 새롭게 생성된 노드는 NodeC를 동시에 가리킴)
  - 이전 노드(NodeB)의 다음 노드로 새로운 노드의 참조값을 저장

        * 새로운 노드가 다음 노드(NodeC)의 참조 값을 저장하기 전에 이전 노드(NodeB)의 다음 노드로 새로운 노드의
           참조값을 먼저 저장하게 된다면 ?
           : 다음 노드(NodeC) 참조 값을 찾을 수 없게 되므로 분실되어 영원히 접근 불가

        * 기본적으로 노드의 삽입은 pointer가 가리키는 노드의 다음 노드에 삽입할 수 있기 때문에
           삽입하려는 위치 전으로 이동해야 함
-----
### 단일 연결리스트(Singly Linked List)의 삭제
-----
1. 맨 앞의 Node를 삭제
<div align = "center">
<img width="1097" alt="7" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/4174d63d-065c-4784-ac2a-4b5124322a16">
</div>   

  - 맨 앞의 노드가 가리키는 다음 노드(NodeB)의 참조값을 알아낸 후, head에 저장   
  - 자연스럽게 삭제할 노드는 연결이 끊어져, JVM는 Garbage Collector의 Scheduling에 따라 메모리에서 제거

2. 중간의 Node를 삭제
<div align = "center">
<img width="1097" alt="8" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/3fcd1d8d-8f73-471b-8cbb-39a1eeadb216">
</div>

  - 노드를 중간에서 삭제할 때 노드와 노드 사이의 연결이 끊어지지 않도록 주의
    : 삭제하려는 노드의 이전 노드와 다음 노드를 연결하는 것이 관건
  - 가장 먼저 삭제하려고 하는 노드의 이전 노드(NodeB)에 pointer가 접근 후, 삭제할 노드의 다음 노드(NodeC)의
    참조값을 이전 노드의(NodeB)의 다음 노드에 저장하면, 이전 노드(NodeB)가 가리키는 노드는 다음 노드(NodeC)를 가리킴
  - 삭제할 노드가 이전 노드(NodeB)와 연결이 끊어지면 자연스럽게 JVM의 Garabage Collector의 Scheduling에 의해 메모리에서 제거

-----
###
-----
<div align = "center">
<img 
</div>

<div align = "center">
<img 
</div>

-----
###
-----
<div align = "center">
<img 
</div>

<div align = "center">
<img 
</div>

-----
###
-----
