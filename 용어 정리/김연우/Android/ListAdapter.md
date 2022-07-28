# ListAdapter란?(DiffUtil,  AsyncListDiffer)

### RecyclerView

RecyclerView를 사용하다보면 아이템을 변경할 일이 많고, 이럴 때 기존에는 notifyDataSetChanged()로 모든 아이템을 업데이트 하는 방법을 사용해 왔다. 하지만 이 방법은 아이템 개수가 많아질수록 비효율적일 수 밖에 없다. 물론 아래 notify- 메서드를 잘 이용하면 전체 데이터를 바꿀 필요가 없지만 position을 가지고 수동으로 관리해 주어야 하는 불편함이 있을 수 있고, 아이템의 정해진 순서가 없을 때는 이 기능을 사용할 수 없다.

 

![img](https://blog.kakaocdn.net/dn/etGeOK/btqELRxEcYH/trPVq3JEcwWv4n5y1jie21/img.png)(RecyclerView 아이템의 변경사항을 notify하는 메서드들)



이런 문제를 알고 구글에서는 DiffUtil이라는 매우 편리한 유틸리티 클래스를 만들었는데, 이 클래스는 두 리스트의 차이점을 찾아 업데이트 되어야 할 목록을 반환 해 줘서 RecyclerView 어댑터에 대한 업데이트를 알리는데 사용된다. 

---



### DiffUtil

'비교'를 하기 위해서는 DiffUtil.Callback()을 구현해야 합니다.

Callback은 아래의 두 메서드를 구현해야합니다.

- areContentsTheSame() : 두 아이템이 동일한 내용물을 가지고 있는지 체크한다. 이 메서드는 areItemsTheSame()가 true일 때만 호출된다.
- areItemsTheSame() : 두 아이템이 동일한 아이템인지 체크한다. 예를들어 item이 자신만의 고유한 id 같은걸 가지고 있다면 그걸 기준으로 삼으면 된다.

DiffUtil.calculateDiff(diffUtil)로 업데이트가 필요한 리스트를 찾습는다.

notifyDataSetChanged()대신 dispatchUpdatesTo(Adapter adapter)를 사용하면 교체가 필요한 아이템에 대해서 부분적으로 데이터를 교체하라는 notify가 실행됩니다.

---



### AsyncListDiffer

위의 DiffUtil을 이용하여 비교연산을 할 때, 비교연산의 코스트가 크다면 백그라운드 스레드에서 처리 하는 것이 좋을 것입니다. 이를 지원해주며, 편리하게 처리 해주기 위해 나온것이 AsyncListDiffer입니다.

AsyncListDiffer의 submitlist 메서드를 통해 이 모든과정이 처리됩니다.

---



### ListAdapter

 ListAdapter는 내부적으로 AsyncListDiffer를 사용하면서, RecyclerView의 adapter처럼 이용이 가능합니다. 따라서 우리는 최종적으로 ListAdapter를 상속하는 adapter 클래스를 만들고, ListAdapter의 파라미터에 diffutil의 callback을 구현해서 넘겨주면 내부에서 submitlist( 바뀔 데이터 ) 라는 하나의 메서드로 모든 작업을 처리 할 수 있습니다.