# git 시작하기

프로젝트 관리할 수 있는 개발자가 되기 위한 실력 기르기



## WHAT

git 의 주요 역할은 version control 이다. 자료를 수정했을 시 이전 자료를 복구할 수 있는 기능을 제공한다. (또한, 주로 모두에게 열려있는 오픈 소스(코드)를 git hub에서 얻을 수 있다.)



## WHY

개발을 한다면 unix 언어를 우선적으로 익히는 것이 유리하다. 사용의 빈도가 높기 때문이다. 하지만 window cmd에서는 unix 명령어를 인식하지 못한다.  그렇기 때문에 git을 사용하는 것이다.  git은 우리가 unix 명령어를 구현한 것을 window가 인식할 수 있도록 자체적으로 번역해준다. 



## HOW

명령어를 익히기 전 기본적으로 폴더와 파일로 구성되어있는 것을 인지하자.

폴더간의 위치에서 `/..` 는 한단계 위를 `/.` 는 나 자신을 가리킨다.



### git 설치

1. git 사이트 (https://git-scm.com/downloads)
2. 컴퓨터 환경에 맞는 파일 다운로드



### git Bash 실행

`git --version` : 제대로 설치 되었는지 체크

`pwd` : 현재 위치 확인



#### git 기본 명령어 정리

- `tab키`  : 문장 자동 완성 (오타 방지)

- `ls` : 파일 확인하기 
  - `ls -a` : 숨김 파일까지 확인
  - `ls -al` : 모든 파일 권한까지 확인
- `cd` : 폴더 이동하기 
  - `cd '폴더 경로'` :폴더 경로로 이동
  - `cd ..` : 한단계 위로 이동
  - `cd ~` : home으로 이동
  - `cd` : home으로 이동
- `mkdir '폴더이름'` : 폴더 생성
- `touch '파일이름'` : 파일 생성
- `rm` : 파일 삭제 (휴지통에서도 사라짐으로 신중하게)
  - `rm '파일이름'` : 파일 삭제
  - `rm -r '폴더이름'` : 폴더 삭제
  - `rm -rf '폴더이름'` : 폴더 강제 삭제
  - `rm -r *` : 전체 삭제
  - `rm -r *.txt` : 텍스트 파일 전체 삭제
- `mv '파일이름' '폴더이름'`  : 파일 이동하기 



#### git master 명령어 정리

- `git init` : master 부여하기(.git 폴더 생성)
  - **주의 **  home 폴더에서는 init 금지
- `git add` : commit 하기 위한 stage 위에 올리기
- `git commit -m '기록'` : stage 위에 올린 파일들을 기록하기
- `git status` :  진행상황(변경사항) 확인하기
- `git log` : commit 한 작업 내역 확인 
- `git config --global user.name` : master 활동 이름
- `git config --global user.email` : master 활동 이메일 
- `git checkout master` : master 상태로 돌아오기
- `git diff '파일이름'` : 파일 변경 내용 확인



(terminal에서 start 명령어는 더블 클릭처럼 사용 가능. 즉, open이다. )



| Working Directory (분장실) |                    | Staging Area (무대) |               | Repository  (촬영) |
| -------------------------- | ------------------ | ------------------- | ------------- | ------------------ |
|                            | -> git add         |                     | -> git commit |                    |
|                            | <-restore --staged |                     |               |                    |







### typora 기본 사용법

**typora는 개발자들의 통일된 문서 양식 이다. (확장자 : md)**



1. 제목 : `#` 의 개수로 설정(Ctrl + 숫자)
2. 내용  
3. 코드 
4. 인라인  
5. 코드블럭 : `'''`  사용. 코드 블럭 생성, 언어 선택으로 가시성 높임
6. 목록 :  `-`  사용 (`숫자.` 는 ordered list)
   - `tab 키` 사용시 추가 들여쓰기 가능
7. 표 : `|` 사용 (Ctrl+enter 행 추가)
8. 수식블럭 : `$$`, Latex사용 
   1.  이모티콘 :  `: '감정'`  ex) :smile:
9.  `ctrl+B` : 굵은 글씨 생성



### Project pre-TODO list :memo:

1. 프로젝트 폴더(디렉토리)를 만든다.
2. `.gitignore` 와 `README.md` 파일을 생성한다.
   1. `gitignore` 파일은, git의 파일 관리에서 무시할 내용(https://www.toptal.com/developers/gitignore)을, 
   2. `README.md` 는 프로젝트의 소개 및 정리 내용을 담는다. 
3. $ `git init` 을 한다!
4. **주의**
   1. `.git/` 폴더와, `.gitignore` 파일과 `README.md ` 파일이 같은 위치에 존재하는가!
5. 첫번째 커밋을 한다!