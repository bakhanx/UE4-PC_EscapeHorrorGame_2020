# UnrealEngine4-PC_EscapeHorrorGame

Pure BluePrint

## Title : Red Night

![main](https://user-images.githubusercontent.com/46181173/117106234-78f86880-adba-11eb-92f3-82bc196fa454.png)<br>

> - 장르 : 공포/미스테리/탈출<br>
> - 개발 : 1인개발 <br>
> - 플랫폼 : PC <br>
> - 언리얼 버젼 : 4.23.1
> - 개발기간 : 2020
> - 스토리라인 : 플레이어가 알 수 없는 집에 들어간 뒤 갇혀 곳곳에 숨겨진 열쇠를 찾아 집을 탈출한다.<br>

## 사용자 인터페이스

![1](https://user-images.githubusercontent.com/46181173/117106616-27041280-adbb-11eb-9f13-d8e603297167.png)

> - 이동 : W A S D <br>
> - 카메라회전 : Mouse Drag<br>
> - 문열기 : LMB<br>
> - 아이템 습득 : E<br>
> - 조사하기(습득상태) : E<br>
> - 확대/축소(조사상태) : Mouse Scroll Up/Down<br>
> - 조사취소 : E<br>
> - 아이템 버리기 : R<br>

## Item Blueprint class (Function)

![function](https://user-images.githubusercontent.com/46181173/117107677-f02efc00-adbc-11eb-883e-0d584187a004.png)<br>

> - 1.PickUp
> - 2.Drop
> - 3.Inspect(Start)
> - 4.Inspect(Stop)

### 1. Pick up

![pickupkey](https://user-images.githubusercontent.com/46181173/117107670-ee653880-adbc-11eb-9ac0-66cd76ae8c49.png)

![pickup](https://user-images.githubusercontent.com/46181173/117107668-edcca200-adbc-11eb-853c-8f517247ae27.png)
정해진 Item을 습득 했을 때 AttachToComponent를 통해 sanp을 하고, 이 item이 문을 열 수 있는 key와 일치하는지에 따라 다른 습득 사운드를 실행한다.

### 2.Drop

![drop](https://user-images.githubusercontent.com/46181173/117108847-bf4fc680-adbe-11eb-9319-e6ae359db494.png)
카메라(플레이어)의 일정 위치 앞에 물건을 떨어뜨린다.

### 3.Inspect Start

![startInspectKey](https://user-images.githubusercontent.com/46181173/117108852-c080f380-adbe-11eb-9d4f-fabdaed3bbea.png)
![frame](https://user-images.githubusercontent.com/46181173/117111124-1c994700-adc2-11eb-979b-9dd0e91fcffb.png)
![startInspect](https://user-images.githubusercontent.com/46181173/117108851-bfe85d00-adbe-11eb-9930-7fadd6749197.png)<br>
화면 우측 하단에 control 인터페이스를 위젯을 통하여 보여주면서 Inspect 동안 플레이어의 카메라 회전을 disable하고 해당 키를 item을 회전할 수 있는 컨트롤로 able한다. Inspect중인 물체는 플레이어의 일정 위치 앞에 배치하여 보여준다.<br>
특정 물체를 잡고 Inspect상태에서 rotate를 통하여 숨겨진 열쇠 발견할 수 있다.

### 4.Inspect Stop

![stopInspect](https://user-images.githubusercontent.com/46181173/117108854-c080f380-adbe-11eb-8e26-71ede978bb12.png)
카메라 회전 키, item의 location과 rotation를 원상태로 돌리고 부모로부터 상속을 제거한 후 타겟의 HUD를 다시 보여준다.

## Door

![door](https://user-images.githubusercontent.com/46181173/117108843-be1e9980-adbe-11eb-9ea7-9b9b8f66e857.png)
![doorimg](https://user-images.githubusercontent.com/46181173/117108846-beb73000-adbe-11eb-8cac-7051b824c9dc.png)
<br>
문에 BoxTrigger를 설정하여 트리거 범위 안에서 플레이어가 'Look At' 했을 때, 문이 닫혀 있으면서 현재 들고 있는 item이 Key인지 체크한 후, 해당 상황에 알맞는 message를 보여준다. 들고 있는 item이 해당 문에 알맞는 key인지 체크하여 문을 연다.

## My Character

![mycharacter](https://user-images.githubusercontent.com/46181173/117108850-bfe85d00-adbe-11eb-96fb-273fd68a5dae.png)<br>

> - Interactive : Inspect, Pickup(Key : E) <br>
> - Click : OpenDoor, Rotate in inspect (Key : MSB) <br>
> - Cancle : Drop (Key : E)

## Level Blueprint

![levelBlueprint](https://user-images.githubusercontent.com/46181173/117108848-bf4fc680-adbe-11eb-8fdc-49fcd6765450.png)
열쇠가 필요하지 않은 가장 첫번 째 문을 따로 만들어 문 근처에 BoxTrigger를 따로 배치하여, 트리거에 플레이어가 도착했을때 , 열고 들어온 문을 역으로 -90도 회전하여 빠르게 닫고 BGM을 시작한다.<br>
마지막 탈출하는 문 밖에도 BoxTrigger를 배치하여, 플레이어가 트리거에 도착했을 때, 입력키를 모두 disable하고 카메라를 fadeout 하며 효과음과 함께 게임을 종료한다.
<br><br>

<p>
<img src= "https://user-images.githubusercontent.com/46181173/118431592-aa095f00-b711-11eb-870f-f3f8a8336f62.png" width=45% height=45% > 
<img src= "https://user-images.githubusercontent.com/46181173/118431623-bc839880-b711-11eb-92be-b4f0f09a91ec.png" width=45% height=45% > 
<img src= "https://user-images.githubusercontent.com/46181173/118431681-dd4bee00-b711-11eb-99a4-56d42b605b60.png" width=45% height=45% > 
<img src= "https://user-images.githubusercontent.com/46181173/118431661-d2915900-b711-11eb-8e4c-24d0b29050c1.png" width=45% height=45% > 
<img src= "https://user-images.githubusercontent.com/46181173/118431696-e3da6580-b711-11eb-91b1-7f0f27fe08c7.png" width=45% height=45% > 
<img src= "https://user-images.githubusercontent.com/46181173/118431732-f8b6f900-b711-11eb-8f13-98a0671a5435.png" width=45% height=45% > 
<img src= "https://user-images.githubusercontent.com/46181173/118431751-00769d80-b712-11eb-8fe4-bc90da2604a8.png" width=45% height=45% > 
<img src= "https://user-images.githubusercontent.com/46181173/118431773-0a000580-b712-11eb-85bc-fa25e518a365.png" width=45% height=45% > 
<img src= "https://user-images.githubusercontent.com/46181173/118431786-13896d80-b712-11eb-942d-19ac9abdb6e9.png" width=45% height=45% > 
<img src= "https://user-images.githubusercontent.com/46181173/118431816-2308b680-b712-11eb-9dbc-d7fbb6837ce9.png" width=45% height=45% > 
<img src= "https://user-images.githubusercontent.com/46181173/118431835-2b60f180-b712-11eb-8f39-76479112b232.png" width=45% height=45% > 
<img src= "https://user-images.githubusercontent.com/46181173/118431849-33b92c80-b712-11eb-80dc-aadb91c3f53b.png" width=45% height=45% > 
<img src= "https://user-images.githubusercontent.com/46181173/118431906-521f2800-b712-11eb-99ea-8c67d62881c2.png" width=45% height=45% >

<img src= "https://user-images.githubusercontent.com/46181173/118431889-4895c000-b712-11eb-9e4a-50431ec6900b.png" width=45% height=45% >

</p>

[![youtube](https://user-images.githubusercontent.com/46181173/117136174-fb951e00-ade2-11eb-862c-0eff3ffe8596.png)](https://youtu.be/3VrJY5Wlmtw?t=0s)<br>
↑ 클릭 [Youtube 이동하기]
