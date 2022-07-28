# DOM

---

## DOM이란?

---

웹페이지에서 자바스크립트로 요소들을 제어하는데 사용<br/>
Document Object Model<br/>
프로그램 언어가 DOM 구조에 접근 할 수 있는 방법을 제공하여 문서 구조, 스타일 등을 변경할 수 있게 돕는 것.

---

### BOM

-   Browser Object Model
    브라우저에서만 접근이 되는 것

예)

```
// DOM
window.document // 웹 개발에서 사용되는 document 객체는 브라우저에서 제공하는 window 객체의 한 요소이다. 즉 이 document객체를 DOM으로 분류

// BOM
window.location
window.navigator
window.screen
```

위 코드에서 window.으로 시작하는 것들처럼 브라우저에서 제공하는 모든 것을 Web Api라고 한다.

### DOM의 생성 과정

html -> 브라우저 -> 코드해석(파싱(Parsing)) -> DOM 생성

### DOM의 구조

HTML요소들의 구조가 트리 형식으로 반영이 됨
<img src="https://miro.medium.com/max/1088/1*NA2VKR09ECb8PEgYDteR3w.gif"> <br/>
위 이미지에서 트리 전체를 DOM, 구성하는 요소 하나하나를 Node라고 부른다. <br/>
자바스크립트로 웹페이지의 요소를 제어할 수 있는 이유는 요소 하나하나가 모두 API이기 때문이다.

### DOM의 특징

<img src="https://ko.javascript.info/article/basic-dom-node-properties/dom-class-hierarchy.svg">
DOM의 상속도

-   위의 이미지에서 EventTarget의 경우 input태그, body태그, a태그 등의 태그들의 상속을 받기 때문에 a,input,body와 같은 태그들에게 접근 할 수 있다.
-   DOM요소들의 고유 기능과 상속관계를 알면 각각에서 무엇을 상속하고 있는지 쉽게 알 수 있다.
