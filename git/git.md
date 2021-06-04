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

- `vim '파일이름'` : '파일이름' 편집하기

  - `:q` 나가기 `:w` 저장 `:wq` 저장하고 나가기 `:q!` 강제 나가기

- `start 파일 이름` :   더블 클릭처럼 사용 가능. 즉, open이다.

- `ctrl`+`L` : git bash 페이지 밀기

  

#### git master 명령어 정리

- `git init` : master 부여하기(.git 폴더 생성)
  - **주의 **  home 폴더에서는 init 금지
  
- `git add` : commit 하기 위한 stage 위에 올리기

- `git commit -m '기록'` : stage 위에 올린 파일들을 기록하기

- `git commit -amend` : 최근 commit 에 덮어쓰거나 이름 바꿀 때 사용 (작업끝나면 ESC 후 `:wq`)

- `git status` :  진행상황(변경사항) 확인하기

- `git log` : commit 한 작업 내역 확인 

  - `git log --oneline` : commit 한 작업 내역 간단하게 확인
  - `git log --oneline -graph` : branch 경로 확인

- `git config --global user.name` : master 활동 이름

- `git config --global user.email` : master 활동 이메일 

- `git checkout master` : master 상태로 돌아오기

- `git diff '파일이름'` : 파일 변경 내용 확인

  



| Working Directory (분장실) |                    | Staging Area (무대) |               | Repository  (촬영) |
| -------------------------- | ------------------ | ------------------- | ------------- | ------------------ |
|                            | -> git add         |                     | -> git commit |                    |
|                            | <-restore --staged |                     |               |                    |



### Project pre-TODO list :memo:

1. 프로젝트 폴더(디렉토리)를 만든다.
2. `.gitignore` 와 `README.md` 파일을 생성한다.
   1. `gitignore` 파일은, git의 파일 관리에서 무시할 내용(https://www.toptal.com/developers/gitignore)을, 
   2. `README.md` 는 프로젝트의 소개 및 정리 내용을 담는다. 
3. $ `git init` 을 한다!
4. **주의**
   1. `.git/` 폴더와, `.gitignore` 파일과 `README.md ` 파일이 같은 위치에 존재하는가!
5. 첫번째 커밋을 한다!



- pycharm 을 사용한다면, pycharm의 terminal을 git으로 설정하자

1. `ctrl`+`Alt`+`S`  
2. 'termianl' 검색 후, tools 선택
3.  shell path 폴더 설정
4.  programFile/git/bin/bash.exe 선택

- `__pycache__ ` : pycharm 실행시 생성

- `idea/..` : 껐다 켜도 작업상황 유지해준다. 지워도 상관없다.
- `.gitignore` 이 위에 두 파일들이 `git add` 에 영향을 주지 않도록 해준다.



### git Branch 다루기

본격적으로 git을 사용한 버전관리는 branch 를 통해서 이루어진다. 용어를 우선적으로 알아보자.



#### git branch 관련 명령어

1. `git branch` : branch 확인
2. `git branch '새 경로'` :  branch '새 경로' 생성
3. `git switch '새 경로'` :  branch '새 경로'로 HEAD 이동
   - `git switch -c '새 경로'` : branch  '새 경로' 생성 후 이동
   - `checkout` + `일렬번호` 와 비슷한 명령어
4. `git commit`:   branch '새 경로' 시작
5.  `git add . && git commit`  
6.  `git switch maste` : 'master' 경로로 HEAD 이동
7. `git merge '새 경로'`: 'master'에 branch '새 경로' 병합
8.  `git branch -d '새 경로'` : branch '새 경로' 삭제



### git hub 사용하기

git hub는 git을 이용하여 관리하는 프로젝트를 저장하는 공간이다.

우선, 컴퓨터(local)에서 생성한 프로젝트를 git hub에서 관리하기 위해서는 연결해줘야 한다.

- git hub에서 프로젝트 전용 저장소 생성(New repository)
- 컴퓨터(local) 와 전용 저장소를 remote 
  - `git remote add '이름' '주소'`
  - `git remote -v` : remote 확인

- `git push '이름' 'branch이름'` : 업로드하기



git hub에서 처음 다운 받는경우 

- `git clone '주소' '이름설정'`



여러명이서 사용하는 프로젝트를 관리한다면

- `git pull origin master`   : 다운받기

- `git switch -c 'branch 이름'`

- `git push origin 'branch 이름'`
- `git branch -d 'branch 이름'`

