[입력받기]
//이렇게하면 space 아니면 ',' 를 구분자로 입력받음
	while (scanf("%d %d", &a, &b) == 2)
	while (scanf("%d,%d"))
	
//	공백포함하여 한줄입력받기
		while (getline(cin, str))
		while (scanf("%[^\n]\n", s) == 1)
		char str[1024]; fgets(str, 1024, stdin); string line(str)

//cin.getline
	iostream에 선언 된걸로 cin.getline(char[], n)하면 n - 1까지 저장하고 n번째는 NULL로 만듬
//getline
	getline(입출력, 저장할 string, 어느문자까지 저장할지) 세번째 매개변수입력안하면	기본적으로 '\n'이다

//버퍼에 남은거 없애기
		// 이거는 출력버퍼를 비워야하는거지 stdin으로 쓰면 위험하다 비운다는건 목적지로 전부 전달하는걸
		fflush(stdin) 
		//의미해서 어떻게 작동할지 모르는 위험성이 있다 linux에서는 입력스트림을 넣으면 작동안함 따라서 getchar가 더나음
		getchar()

	"%*c%c" 라는 형식 문자열의 의미는 "stdin 에서 한 문자를 얻어오되 그 값은 버리고 (이 경우 \n 이 버려진다), 
			그 다음에 한 문자를 얻어와 이에 대응되는 인자 (&c) 에 저장한다" 이기 때문이다.

//버퍼비우는 코드
		getchar()는 버퍼에서 문자하나를 읽음
		while (getchar() != '\n');

//문자하나받기
		cin.get()하면 char형의 아스키코드로 저장됨(숫자 0은 48)
		scanf("%1s") 였나?	

//문자열에서 특정위치까지 자르기
	string.substr(시작, 개수)
	string.size()

[정렬]
//sort
	<algorithm> sort(시작주소, 끝주소, 비교함수)

	그래프만들때 [][] 2차원 배열만들어서 하거나 아니면
	vector만들어서 .push_back()하고 탐색할때 .size()까지 해서 하던가 만약 조건에 작은것부터 방문이면 sort해야함
	sort(vector[i].begin(), vector[i].end()) 이렇게 

	들어온 입력순서를 유지해서 정렬하는 방법
	stable_sort() 이게 아마 sort방식에 따라 입력순서가 유지안되는걸 유지되게 만들어줌
	ex) age, order, string 이렇게 있으면 age순으로 비교하고 같으면 order을 비교

	정렬이 pq가 빠른지 heap이 빠른지 sort가 빠른지 찾아보기


//우선순위큐
	sort()를 사용해서 정렬할때 시간이 오래 걸린다면
	priority queue를 사용해보자 시간복잡도는 NlogN vs logN임

	//최소힙
	priority_queue<타입, vector<타입>, greater<타입>> pq;
	pq.push / pq.top / pq.pop


//내림차순으로 정렬
	#include <functional>
	sort(시작, 끝, greater<int>())

[그래프]
//DFS
		재귀 or stack
		길찾기같은거 할때
//BFS
		Queue
		최단거리 찾을때 -> dist[][]를 해서 이전거리 + 1해서 현재 거리 갱신

//bool 변수 초기화할때
	한번에 초기화 memset(arr[], 채울값, 크기)
	1Bytes 변수(char, unsigned char 등)를 제외한 변수를 초기화 할 때에는
	0이외의 값으로 초기화를 하면 안됩니다.
	그래서 보통 char나 bool형일때만 사용함


2331번 재방문 여부의 문제
	visit[]로 재방문했는지 아닌지를 확인해도되지만 
	그냥 바로 거기에 count를 넣어서 값있으면 방문했다고 판단해도됨

2178번 최단거리 문제
	bfs를 사용해서 dist[][] 배열을 사용해서 해결