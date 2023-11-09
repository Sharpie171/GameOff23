// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatManager.h"

UCombatManager::UCombatManager()
{
	// Setup the arrays to their defaults
	for (int i = 0; i < minPackets; i++) {
		FCombatPacket newPacket = FCombatPacket();
		newPacket.packetId = i;
		CombatPackets.Push(newPacket);
		reserved.Push(false);
	}
}

UCombatManager::~UCombatManager()
{
}

FCombatPacket UCombatManager::requestPacket()
{
	// If one of the combat packets already allocated is not reserved, return it
	for (int i = 0; i < CombatPackets.Num(); i++) {
		if (!reserved[i]) {
			reserved[i] = true;
			return CombatPackets[i];
		}
	}
	// Allocate a new packet, mark it as reserved, and return it
	return createPacket(true);
}

void UCombatManager::returnPacket(FCombatPacket returnedPacket)
{
	// Mark packet as unreserved
	reserved[returnedPacket.packetId] = false;
	// Create a new packet
	CombatPackets[returnedPacket.packetId] = FCombatPacket();
}

FCombatPacket UCombatManager::createPacket(bool reserve)
{
	// Called to add a packet to the Tarrays
	FCombatPacket newPacket = FCombatPacket();
	CombatPackets.Push(newPacket);
	reserved.Push(reserve);
	return newPacket;
}
