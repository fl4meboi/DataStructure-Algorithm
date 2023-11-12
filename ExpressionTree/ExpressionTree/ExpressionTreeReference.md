## 참고 영상 
https://www.youtube.com/watch?v=qvJGRsE9ukI&list=PLl5LpJCoD2mCIRn0Fkt8z07EK320ZmHgY&index=46

## 정의 
- 수식을 연산 순서에 따라 트리로 구성
- Root에 Operator, Child에 Operand를 배치
- Operand => Leaves / Operator => Internal Nodes
- PostOrder Traverse(후위순회)로 표기하는 것이 가장 효율적 
   => 컴퓨터의 입장에서 이해하기 가장 쉬움 

## 알고리즘 
1. Operand는 Node를 만들어서 Stack에 Push
2. Operator는 Node를 생성하여 
	1. Stack에서 Pop한 Node를 RightChild로 하고 
	2. Stack에서 또 Pop한 Node를 LeftChild로 하고 
	3. Operator Node를 Stack에 Push
3. Stack에 마지막으로 남은 Node가 Root이다. 