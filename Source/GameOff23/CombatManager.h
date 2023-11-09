// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CombatManager.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FCombatPacket
{
    GENERATED_BODY()

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat Manager")
            AActor* attacker;
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat Manager")
            AActor* TargetActor;
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat Manager")
            FVector targetLocation;
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat Manager")
            TArray<AActor*> victims;
        int packetId;
};

UCLASS(BlueprintType)
class GAMEOFF23_API UCombatManager : public
    UObject
{
    GENERATED_BODY()


public:
    UCombatManager();
	~UCombatManager();
    UFUNCTION(BlueprintCallable, Category = "Combat Manager")
    FCombatPacket requestPacket();
    UFUNCTION(BlueprintCallable, Category = "Combat Manager")
    void returnPacket(FCombatPacket returnedPacket);
private:
    // Keep track of which packets have been reserved
    TArray<bool> reserved;
    // Create a new packet
    FCombatPacket createPacket(bool reserve);
    // Hold the allocated combat packets.
    TArray<FCombatPacket> CombatPackets;
    // Define a minimum number of combat packets to hold in the array
    int minPackets = 3;
};
