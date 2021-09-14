#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 구조체는 복합 자료형이다

// 구조체를 선언하고 멤버를 사용하는 방법

/*
struct student          // 멤버 선언
{
    int num;
    double grade;
};


int main()
{
    struct student s1;  // 구조체 변수를 선언하면 저장공간 할당, 이는 각 멤버의 크기를 더한 값이 됨 (12바이트)

    s1.num = 2;         // 멤버 접근 연산자
    s1.grade = 2.7;
    printf("학번 : %d\n",s1.num);
    printf("학점 : %.1lf\n",s1.grade);

    return 0;
}
*/

// 구조체는 일정한 크기 단위로 메모리에 접근하기때문에 멤버의 크기가 들쑥날쑥한 경우 패딩바이트를 추가한다 ex) 12바이트 -> 16바이트
// 그러므로 구조체를 선언할때 멤버의 순서에 주의하면 메모리를 아낄수있다
// 구조체 선언 위치
// 메인 함수 앞에  선언하면 프로그램 전체에서 사용가능하며
// 함수 안에 선언하면 그 함수 안에서만 사용가능하다

// 다양한 구조체 멤버, 배열과 포인터르 멤버로 갖는 구조체 사용

/*
struct profile
{
    char name[20]; // 이름을 저장할 배열 멤버
    int age;       // 나이
    double height; // 키
    char *intro;   // 자기소개를 위한 포인터
};

int main()
{
    struct profile yuni;

    strcpy(yuni.name, "서하윤");
    yuni.age = 17;
    yuni.height = 164.5;
    
    yuni.intro = (char *)malloc(80);        // 자기소개를 저장할 공간을 동적할당
    printf("자기소개 : \n");                  
    gets(yuni.intro);                       // 자기소개 입력

    printf("이름 : %s\n",yuni.name);
    printf("나이 : %d\n",yuni.age);
    printf("키 : %.1lf\n",yuni.height);
    printf("자기소개 : %s\n",yuni.intro);
    free(yuni.intro);

    return 0;
}
*/

// 구조체의 멤버로 다른 구조체 사용하기

// 다른 구조체를 멤버로 갖는 구조체 사용

/*
struct profile
{
    int age;
    double height;
};

struct student
{
    struct profile pf;      // profile의 구조체를 멤버로사용
    int id;
    double grade;
};


int main()
{
    struct student yuni;

    yuni.pf.age = 17;
    yuni.pf.height = 164.5;
    yuni.id = 315;
    yuni.grade = 4.3;

    printf("나이 : %d\n",yuni.pf.age);
    printf("키 : %.1lf\n",yuni.pf.height);
    printf("학번 : %d\n",yuni.id);
    printf("학점 : %.1lf\n",yuni.grade);
    
    return 0;
}
*/

// 구조체 변수의 초기화와 대입 연산

// 최고 학점의 학생 데이터 출력

/*
struct student
{
    int id;
    char name[20];
    double grade;
};

int main()
{
    struct student s1 = {315, "홍길동", 2.4},
                   s2 = {316, "이순신", 3.7},
                   s3 = {317, "세종대왕", 4.4};

    struct student max;     // 최고 학점을 저장할 구조체 변수

    max = s1;
    if(s2.grade > max.grade) max = s2;
    if(s3.grade > max.grade) max = s3;
    
    printf("학번 : %d\n",max.id);
    printf("이름 : %s\n",max.name);
    printf("학점 : %.1lf\n",max.grade);

    return 0;
}
*/

// 구조체를 반환하여 두 변수의 값 교환

/*
struct vision
{
    double left;
    double right;
};

struct vision exchange(struct vision robot);

int main()
{
    struct vision robot;

    printf("시력 입력 : ");
    scanf("%lf%lf", &(robot.left), &(robot.right));
    robot = exchange(robot);
    printf("바뀐 시력 : %.1lf %.1lf\n", robot.left, robot.right);

    return 0;
}

struct vision exchange(struct vision robot)
{
    double temp;

    temp = robot.left;
    robot.left = robot.right;
    robot.right = temp;

    return robot;
}
*/

/*
struct book
{
    char title[20];
    char author[20];
    int page;
    int price;
};
*/

/*
struct cracker
{
    int price;
    int calories;
};

int main()
{
    struct cracker cookie;

    printf("바사삭의 가격과 열량을 입력하세요 : ");
    scanf("%d%d",&cookie.price,&cookie.calories);
    printf("바사삭의 가격 : %d\n",cookie.price);
    printf("바사삭의 열량 : %d\n",cookie.calories);

    return 0;
}
*/

/*
1번 동적할당 안함
2번 배열명은 주소 상수이기 때문에 왼쪽에 못옴 이경우에 strcpy함수를 써야함
3번 접근이 잘못됨
4번 동적할당 안함
*/

// 구조체 활용, 공용체, 열거형

// 구조체 포인터 사용
// -> 연산자를 쓰는 이유는 멤버 접근 연산자인 .연산자가
// * 연산자보다 우선 순위가 높아 (*ps).kor 이처럼 괄호를 묶어줘야 하므로 번거롭기때문에 -> 연산자를 사용한다
/*
struct score
{
    int kor;
    int eng;
    int math;
};

int main()
{
    struct score yuni = {90, 80, 70}; // 수조체 변수 선언과 초기화
    struct score *ps = &yuni;         // 구조체 포인터에 주소 저장

    printf("국어 : %d\n", (*ps).kor);   // 구조체 포인터로 멤버 접근
    printf("영어 : %d\n", ps->eng);     // -> 연산자로 멤버 접근
    printf("수학 : %d\n", ps->math);

    return 0;
}
*/

// 구조체 배열을 초기화하고 출력

/*
struct address
{
    char name[20];
    int age;
    char tel[20];
    char addr[80];
};

int main()
{
    struct address list[5] =                // 요소가 5개인 구조체 배열 선언
        {
            {"홍길동", 23, "111-1111", "울릉도 독도"},
            {"이순신", 35, "222-2222", "서울 건천동"},
            {"장보고", 19, "333-3333", "완도 청해진"},
            {"유관순", 15, "444-4444", "충남 천안"},
            {"안중근", 45, "555-5555", "황해도 해주"}};
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%10s%5d%15s%20s\n",
               list[i].name, list[i].age, list[i].tel, list[i].addr);
    }

    return 0;
}
*/

// 구조체 배열을 처리하는 함수
// 함수에서 -> 연산자를 사용하여 구조체 배열의 값 출력

/*
struct address
{
    char name[20];
    int age;
    char tel[20];
    char addr[80];
};

void print_list(struct address *lp);

int main()
{
    struct address list[5] = // 요소가 5개인 구조체 배열 선언
        {
            {"홍길동", 23, "111-1111", "울릉도 독도"},
            {"이순신", 35, "222-2222", "서울 건천동"},
            {"장보고", 19, "333-3333", "완도 청해진"},
            {"유관순", 15, "444-4444", "충남 천안"},
            {"안중근", 45, "555-5555", "황해도 해주"}};

    print_list(list);

    return 0;
}

void print_list(struct address *lp)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%10s%5d%15s%20s\n",
               (lp + i)->name, (lp + i)->age, (lp + i)->tel, (lp + i)->addr);
    }
}
*/

// 자기 참고 구조체
// 자기 참고 구조체로 list 만들기

/*
struct list
{
    int num;
    struct list *next;      // 구조체 자신을 가리키는 포인터 멤버
};

int main()
{
    struct list a = {10, 0}, b = {20, 0}, c = {30, 0}; // 구조체 변수 초기화
    struct list *head = &a, *current;                  // 헤드 포인터 초기화

    a.next = &b; // a의 포인터 멤버가 b를 가리킴
    b.next = &c; // b의 포인터 멤버가 c를 가리킴

    printf("head->num : %d\n", head->num); // head가 가리키는 a의 num 멤버 사용
    printf("head->next->num : %d\n", head->next->num);

    printf("list all : ");
    current = head;         // 최초 current 포인터가 a를 가리킴 (연결 리스트를 가리키는 역할)
    while (current != NULL) // 마지막 구조체 변수까지 출력하면 반복 종료
    {
        printf("%d  ",current->num);    // current가 가리키는 구조체 변수의 num 출력
        current = current -> next;      // current가 다음 구조체 변수를 가리키도록 함
    }
    printf("\n");

    return 0;
}
*/

// 연결 리스트 == 구조체 변수를 포인터로 연결한것

// 공용체
// 공용체를 사용한 학번과 힉점 데이터 처리

/*
union student
{
    int num;
    double grade;
};

int main()
{
    union student s1 = { 315 };

    printf("학번 : %d\n",s1.num);
    s1.grade = 4.4;
    printf("학점 : %.1lf\n",s1.grade);
    printf("학번 : %d\n",s1.num);

    return 0;
}
*/

// 열거형
// 열거형을 사용한 프로그램

/*
enum season {SPRING, SUMMER, FALL, WINTER};     // 열거형 선언

int main()
{
    enum season ss;     // 열겨형 변수 선언
    char *pc = NULL;    // 문자열을 저장할 포인터

    ss = SPRING;
    switch (ss)
    {
    case SPRING:
        pc = "inline"; break;
    case SUMMER:
        pc = "swimming"; break;
    case FALL:
        pc = "trip"; break;
    case WINTER:
        pc = "skiing"; break;
    }
    printf("나의 레저 활동 => %s\n",pc);

    return 0;
}
*/

/*
typedef struct student Student;		//Student로 재정의
void print_data(Student *ps);

int main()
{
	Student s1 ={ 315, 4.2};
	
	print_data(&s1);	//Student형 변수의 주소 전달
	
	return 0;
}

void print_data(Student *ps)
{
	printf("학번 : %d\n",ps->num);
	printf("학점 : %.1lf\n",ps->grade);
}
*/

// 이처럼 새로 정의한 이름으로 간단하게 사용이 가능하다 물론 재정의 전의 이름도 사용가능하다
// 보통 재정의된 자료형의 이름은 대문자로 쓴다

// 마무리

// 1번
/*
typedef struct marriage
{
    char name[20];
    int age;
    char sex;
    double height;
} Marriage;
Marriage m1 = {"Andy", 22,'m',187.5};
Marriage *mp = &m1;

int main()
{
    printf("이름 : %s\n",mp->name);
    printf("나이 : %d\n",mp->age);
    printf("성별 : %c\n",mp->sex);
    printf("신장 : %.1lf\n",mp->height);

    return 0;
}
*/

// 2번

/*
typedef struct train
{
    int seats;         // 객차의 좌석수
    struct train *next // 다음 객차를 연결할 포인터
} Train;

int main()
{
    Train *head = NULL, *tail = NULL; // 머리와 꼬리 부분을 NULL값으로 초기화
    int i;
    for (i = 0; i < 5; i++) // 총 5칸의 연결 리스트 생성
    {
        if (head == NULL)
        {
            head = tail = (Train *)malloc(sizeof(Train)); // 첫 머리를 구조체의 메모리 크기만큼 할당
        }
        else
        {
            tail->next = (Train *)malloc(sizeof(Train)); // 머리 다음 부분부터 구조체의 메모리 크기만큼 할당
            tail = tail->next;  //  tail포인터가 항상 연결 리스트의 마지막 부분을 기억하도록 저장
        }
    }

    return 0;
}
*/

// 3번

// 왼쪽

// 도전 실전 예제

/*
typedef struct
{
    int num;           // 학번
    char name[20];     // 이름
    int kor, eng, mat; // 3과목 점수
    int tot;           // 총점
    double avg;        // 평균
    char grade;        // 학점
} Student;

void input_data(Student *pary);
void calc_data(Student *pary);
void sort_data(Student *pary);
void print_data(Student *pary);

int main(void)
{
    Student ary[5]; // 5명 학생의 성적

    input_data(ary); // 학번, 이름, 3과목 점수 입력
    calc_data(ary);  // 총점, 평균, 학점 계산

    printf("# 정렬 전 데이터...\n");
    print_data(ary); // 정렬 전 출력
    sort_data(ary);  // 총점 순으로 내림차순 정렬
    printf("\n# 정렬 후 데이터...\n");
    print_data(ary); // 정렬 후 출력

    return 0;
}

void input_data(Student *pary)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("> 학번 : ");
        scanf("%d", &pary->num);
        printf("> 이름 : ");
        scanf("%s", pary->name);
        printf("> 국어, 영어, 수학 점수 : ");
        scanf("%d%d%d", &pary->kor, &pary->eng, &pary->mat);

        pary++;
    }
}

void calc_data(Student *pary)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        pary->tot = pary->kor + pary->eng + pary->mat;
        pary->avg = pary->tot / 3.0;
        if (pary->avg >= 90.0) pary->grade = 'A';
        else if (pary->avg >= 80.0) pary->grade = 'B';
        else if (pary->avg >= 70.0) pary->grade = 'C';
        else pary->grade = 'F';

        pary++;
    }
}

void sort_data(Student *pary)   // 버블정렬
{
    Student temp;
    int i, j;
    int max;

    for (i = 0; i < 4; i++)
    {
        max = i;
        for (j = i + 1; j < 5; j++)
        {
            if (pary[max].tot < pary[j].tot)
            {
                max = j;
            }
        }
        if (max != i)
        {
            temp = pary[max];
            pary[max] = pary[i];
            pary[i] = temp;
        }
    }
}

void print_data(Student *pary)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%5d%7s%5d%5d%5d%5d%7.1lf%5c\n",
               pary->num, pary->name, pary->kor, pary->eng,
               pary->mat, pary->tot, pary->avg, pary->grade);
        pary++;
    }
}
*/

