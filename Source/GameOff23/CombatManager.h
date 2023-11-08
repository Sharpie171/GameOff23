// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
};

class GAMEOFF23_API CombatManager
{
public:
	CombatManager();
	~CombatManager();
    UFUNCTION(BlueprintCallable, Category = "Combat Manager")
    FCombatPacket* requestPacket();
    UFUNCTION(BlueprintCallable, BlueprintReadWrite, Category = "Combat Manager")
    void returnPacket();
private:
    // Keep track of which packets have been reserved
    TArray<bool> reserved;
    // Create a new packet
    FCombatPacket* createPacket();
    // Hold the allocated combat packets.
    TArray<FCombatPacket*> CombatPackets;
    // Define a minimum number of combat packets to hold in the array
    int minPackets = 3;
};
