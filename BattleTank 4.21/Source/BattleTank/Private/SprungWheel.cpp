// Copyright Lukasz Cieplak

#include "SprungWheel.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PostPhysics;


	Spring = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Spring"));
	SetRootComponent(Spring);

		//Setup default angular limits
		Spring->SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Locked, .0f);
		Spring->SetAngularSwing2Limit(EAngularConstraintMotion::ACM_Locked, .0f);
		Spring->SetAngularTwistLimit(EAngularConstraintMotion::ACM_Locked, .0f);

		//Setup default linear limits
		Spring->SetLinearXLimit(ELinearConstraintMotion::LCM_Locked, .0f);
		Spring->SetLinearYLimit(ELinearConstraintMotion::LCM_Locked, .0f);
		Spring->SetLinearZLimit(ELinearConstraintMotion::LCM_Free, .0f);

		//Setup default linear motor
		Spring->SetLinearPositionDrive(false, false, true);
		Spring->SetLinearVelocityDrive(false, false, true);
		Spring->SetLinearDriveParams(500.0f, 200.0f, 0.0f);

	Axel = CreateDefaultSubobject<USphereComponent>(FName("Axel"));
	Axel->SetSimulatePhysics(true);
	Axel->SetupAttachment(RootComponent);

	WheelRollConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Wheel Roll Constraint"));
	WheelRollConstraint->SetupAttachment(Axel);

	Wheel = CreateDefaultSubobject<USphereComponent>(FName("Wheel"));
	Wheel->SetSimulatePhysics(true);
	Wheel->SetupAttachment(Axel);


}
// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();

	Wheel->SetNotifyRigidBodyCollision(true);
	Wheel->OnComponentHit.AddDynamic(this, &ASprungWheel::OnHit);

	SetupConstraints();
}

void ASprungWheel::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	ApplyForce();
}

void ASprungWheel::SetupConstraints()
{

	if (!GetAttachParentActor()) return;
	UPrimitiveComponent* BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());

	if (!BodyRoot) return;

	Spring->SetConstrainedComponents(BodyRoot, NAME_None, Axel, NAME_None);
	WheelRollConstraint->SetConstrainedComponents(Axel, NAME_None, Wheel, NAME_None);


}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetWorld()->TickGroup == TG_PostPhysics)
	{
		DrivingForce = 0;
	}

}

void ASprungWheel::AddDrivingForce(float ForceMagniture)
{
	DrivingForce += ForceMagniture;
}

void ASprungWheel::ApplyForce()
{
	Wheel->AddForce(Axel->GetForwardVector() * DrivingForce);
}
