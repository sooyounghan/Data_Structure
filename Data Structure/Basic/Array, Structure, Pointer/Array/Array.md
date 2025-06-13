-----
### 배열
-----
1. 동일한 타입의 데이터를 한 번에 여러 개 만들 때 사용
```c
int list[6];
```
2. 연속적인 메모리 공간이 할당되고, 인덱스(Index) 번호를 사용하여 쉽게 접근이 가능해 반복 루프를 이용해 여러 가지 작업 손쉽게 가능
<div align="center">
<img src="https://github.com/user-attachments/assets/ce7fa14e-b2a6-4bc5-98d0-63053fe61fd4">
</div>

3. 배열 ADT
   - ```<인덱스, 값>```의 쌍으로 이루어진 집합으로 정의 가능
   - 즉, 인덱스가 주어지면 해당하는 값이 대응되는 자료 구조
   - 주어진 인덱스에 값을 저장하는 연산 : set(=store)
   - 인덱스가 주어지면 해당되는 값을 추출하는 연산 : get(=retrieve)
<div align="center">
<img src="https://github.com/user-attachments/assets/be781684-0d89-4c84-834e-3ee88cf53893">
</div>

4. C언어에서 1차원 배열
   - 배열은 변수 이름 끝에 []을 추가하여 선언 ([] 안 숫자는 배열의 크기)
```c
int list[6]; // create 연산
```
   - [] 연산자를 사용하여서 인덱스의 값을 가져오거나 값 저장 가능
```c
list[0] = 100; // set 연산
value = list[0]; // get 연산
```
<div align="center">
<img src="https://github.com/user-attachments/assets/734092ae-014e-491c-983a-d9aa52aec8d7">
</div>

  - 컴파일러는 배열에 메모리를 연속된 위치에 할당
<div align="center">
<img src="https://github.com/user-attachments/assets/786d2f44-aa23-457c-ab00-afc7babbcfcd">
</div>

  - 즉, 주소 base + i * sizeof(자료형)에 있는 값을 가져옴

5. 2차원 배열
   - 2차원 형태로 나열된 배열로, 가로줄을 행(Row), 세로줄을 열(Column)이라고 함
```c
int list[3][5];
```
<div align="center">
<img src="https://github.com/user-attachments/assets/0819a8d4-2c23-4ba7-aacc-57b371010b7c">
<img src="https://github.com/user-attachments/assets/8f472ba0-8d28-4bfb-a25b-4353ab145257">
</div>
