#include "BTTask_Shoot.h"
#include "AIController.h"
#include "EnemyCharacter.h"
UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = "Shoot";
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
 
	if (OwnerComp.GetAIOwner() == nullptr) 
	{
		return EBTNodeResult::Failed;
	}
 

	AEnemyCharacter* enemyOwner = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (enemyOwner)
	{
		enemyOwner->shootGun();
	}

	return EBTNodeResult::Succeeded;
}

