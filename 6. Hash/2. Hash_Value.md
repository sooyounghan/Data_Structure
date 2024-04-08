-----
### Hash Value = Hash Code
-----
<div align = "center">
<img width="1097" alt="1" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/57d2613b-181b-4a05-8a98-035faf63d5d4">
</div>

: 어떤 값이 해시 함수를 통과하여 특정 값으로 매핑되어 반환 되는 값

-----
### Hash Fuction
-----
<div align = "center">
<img width="1097" alt="2" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/bf3729d4-49be-47b5-bcf7-5ea18e0cb064">
</div>

1. 어떤 값을 전달받아 특정 알고리즘에 의해 특정 값으로 매핑하여 반환하는 함수
2. 호출 횟수에 상관 없이 동일한 값을 동일한 해시 함수에 전달하면, 항상 동일한 해시값을 반환해야 함

            특정한 값 : 정수, 실수, 문자, 파일 등 다양한 형태의 자료를 뜻함
3. 해시 함수의 예 : 자바의 hashCode(), MD5, SHA 등

-----
### Hash Value의 특징
-----
1. 해시값은 충돌 가능성이 있음
<div align = "center">
<img width="1097" alt="3" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d3c9643f-8b6d-4df3-a212-6cd2d270cb0f">
</div>   

  - 동일한 해시 함수에 서로 다른 값을 전달했을 때 동일한 해시값을 반환하는 것
  - 해시 함수의 알고리즘에 따라 충돌 가능성이 달라지며, 완전히 충돌하지 않는 해시 함수는 존재하지 않음

2. 해시값과 해시 함수만으로 원본 값을 알아내기 어려움
<div align = "center">
<img width="1098" alt="4" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/a145897a-da75-43b6-a5ea-d31c3f515751">
</div>

  - 해시 함수의 특성상 비복호화를 어느 정도 염두에 두고 제작
  - 특정한 값이 아니고서 해시 함수와 해시 값만으로 원본 값을 알아내기 어려움
  - 무작위 값 대입을 통해 동일한 해시 코드를 찾아내어 원본을 알아내는 방법도 있으나,
    이는 해시값의 충돌 가능성도 있기 때문에 동일한 해시값을 찾아냈다고 보기 어려움

-----
### Hash Value과 Hash Fuction을 사용하는 이유
-----   
1. 파일의 무결성 확인
   
  - 소프트웨어 다운로드 시, Checksum 또는 Hash Value가 공개된 경우 존재
  - 해당 해시값은 원본 파일의 무결성을 확인하기 위해 사용

<div align = "center">
<img width="1096" alt="5" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/fdb54296-38d6-4fd0-9f55-3f27becabbd7">
</div>

  - 공식 페이지가 아닌 다른 곳에서 특정 소프트웨어를 다운로드 하는 경우
  - 파일을 악의적으로 변조해서 올리는 경우 존재하므로 해당 소프트웨어 변조 여부 확인 (무결성 확인)
  - 원본 파일의 해시값을 안다면, 다운로드한 소프트웨어의 해시값과 대조해 변조 여부 판단
   

<div align = "center">
<img width="1098" alt="6" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/a624ef84-32cb-4676-8563-cdffc7672eb1">
</div>   

    > 자바 / MySQL 다운로드 시 CheckSum 확인 가능

- MAC Terminal (SHA256)
```Linux
$ openssl dgst -sha256 /파일패스/파일명
```

- MAC Terminal (MD5)
```Linux
$ md5 /파일패스/파일명
```

2. 복호화가 필요 없는 암호화
<div aling = "center">
<img width="1097" alt="7" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/0a272299-7f50-449b-82bc-a85e97f63de0">
</div>

  - 해시 함수는 복호화가 필요 없는 암호화가 필요할 때 사용되기도 함

<div aling = "center">
<img width="1097" alt="8" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/064dfc72-c253-436f-9aed-e777d3081b8b">
</div>

   - 비밀번호를 복호화 되지 않는 해시 코드로 저장하는 경우에 해당
   - 서비스 개발자가 사용자 아이디와 비밀번호 원본을 알면, 악의적으로
     다른 서비스에 무작위 대입으로 로그인 시도 가능
   - 사용자의 비밀번호를 복호화되지 않는 단일 방향 암호화하여 저장

3. 해시 테이블의 버킷 인덱스
<div aling = "center">
<img width="1098" alt="9" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/c4a12216-c583-4c5c-9004-0a95c44f0e64">
</div>

  - 해시 테이블 자료구조에서 버킷 접근을 위한 인덱스를 만들기 위해 특정 해시함수 제작

-----
### 자바의 자료형과 다양한 해시 함수
-----   
1. 자바에는 각 자료형의 해시값을 반환하는 hashCode() 메서드 존재
2. 이 메서드는 Collection 라이브러리의 HashTable과 HashMap에서 사용
3. hashCode() 메서드는 자바 가상 머신의 버전에 따라 해시 함수 알고리즘이 다를 수 있음

4. booelan
```java
public int hashCode() {
    return Boolean.hashCode(value);
}

public static int hashCode(boolean value) {
    return value ? 1231 : 1237;
}
```

5. Integer
```java
public int hashCode() {
    return Integer.hashCode(value);
}

public static int hashCode(int value) {
    return value;
}
```

6. Double
```java
public int hashCode() {
    return Double.hashCode(value);
}

public static int hashCode(int value) {
   long bits = doubleToLongBits(value);
   return (int)(bits ^ (bits >>> 32));
}
```

7. Character
```java
public int hashCode() {
    return Character.hashCode(value);
}

public static int hashCode(char value) {
    return (int)(value)
}
```

8. String
```java
public int hashCode() {
    int h = hash;
    if (h == 0 && value.length > 0) {
        char[] val[] = value;
        for (int i = 0; i < value.length; I++) {
            h = 31 * h + val[i];
        }
        hash = h;
    }
    return h;
}
```

9. Obect
```java
public native int hashCode();
```

: Object Class의 hashCode() native 메서드로 자바 가상 머신 내에서 생성

   
