-----
### 추상 자료형 (ADT : Abstract Data Type)
-----
1. 자료형 (Data Type) : 데이터의 종류
   - 참고 : C에서의 자료형
<div align="center">
<img src="https://github.com/user-attachments/assets/86dcc667-af02-44f6-8835-ae21b5e876dd">
</div>

2. 자료형은 데이터뿐만 아니라, 데이터 간에 가능한 연산도 고려해야함
3. 추상 자료형 (ADT : Abstract Data Type)
   - 추상적으로, 수학적으로 자료형을 정의한 것
   - 자료구조는 추상 자료형을 프로그래밍 언어로 구현한 것

4. 추상화 : 어떤 시스템을 간략화된 기술 또는 명세로서, 시스템의 핵심적인 구조나 동작에만 집중하는 것
   - 좋은 추상화 : 사용자에게 중요한 정보는 강조, 중요하지 않은 구현 세부 사항은 제거되는 것
   - 이를 위해 정보 은닉 기법(Information Hiding)이 개발되었고, 이것이 추상 자료형의 개념으로 발전
<div align="center">
<img src="https://github.com/user-attachments/assets/d36f588b-63d2-4163-8cf2-875319e73480">
</div>

5. 즉, ADT는 실제적 구현으로부터 분리되어 있는 자료형
   - 데이터나 연산이 무엇(What)인지는 정의되지만, 데이터나 연산을 어떻게(How) 컴퓨터 상에서 구현할 것인지는 정의되지 않음
   - 단, 연산을 정의하는 추상적인 의사코드는 주어질 수 있음
   - 예시) 자연수를 나타내는 추상 자료형 정의
<div align="center">
<img src="https://github.com/user-attachments/assets/8d4271c8-f236-440c-9dba-2aead1a32456">
</div>

   - ADT 안에는 객체(Objectss)와 함수(Functions)들이 정의
     + 객체 : 집합의 개념을 사용하여 정의
     + 이후, 함수들이 정의
     + 함수 : 연산을 의미 (함수의 이름, 매개변수, 반환형, 수행하는 기능의 기술 포함)
   - ```:==``` : ~으로 정의된다를 의미
   - ADT가 구현될 때 구현 세부사항은 외부에 알리지 않고, 외부와의 인터페이스만을 공개
   - 객체지향언어에서는 '클래스' 개념을 사용해서 ADT가 구현
     + 객체 : 클래스의 속성으로 구현
     + 연산 : 클래스의 멤버함수로 구현

6. 예시 - Boolean 추상 자료형
```adt
And(A1, A2) :== if (A1 == 1 and A2 == 1) then return TRUE;
                else then return FALSE;

Or(A1, A2) :== if (A1 == 0 and A2 == 0) then return FALSE;
               else then return TRUE;

Not(A) :== if (A == 0) then return TRUE;
           else return FALSE;

Xor(A1, A2) :== if((A1 == 1 and A2 == 1) or (A1 == 0 and A2 == 0)) then return FALSE;
                else then TRUE;
```
