#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class AMyActor : public AActor
{
    GENERATED_BODY()

public:
    // 이 액터의 프로퍼티에 기본값을 설정합니다.
    AMyActor();

    // 매 프레임 호출됩니다.
    virtual void Tick( float DeltaSeconds ) override;

protected:
    // 게임 시작 또는 스폰시 호출됩니다.
    virtual void BeginPlay() override;
};
