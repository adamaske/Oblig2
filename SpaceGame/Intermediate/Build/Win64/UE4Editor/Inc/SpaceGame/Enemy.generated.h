// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SPACEGAME_Enemy_generated_h
#error "Enemy.generated.h already included, missing '#pragma once' in Enemy.h"
#endif
#define SPACEGAME_Enemy_generated_h

#define SpaceGame_Source_SpaceGame_Enemy_h_12_SPARSE_DATA
#define SpaceGame_Source_SpaceGame_Enemy_h_12_RPC_WRAPPERS
#define SpaceGame_Source_SpaceGame_Enemy_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define SpaceGame_Source_SpaceGame_Enemy_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemy(); \
	friend struct Z_Construct_UClass_AEnemy_Statics; \
public: \
	DECLARE_CLASS(AEnemy, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceGame"), NO_API) \
	DECLARE_SERIALIZER(AEnemy)


#define SpaceGame_Source_SpaceGame_Enemy_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAEnemy(); \
	friend struct Z_Construct_UClass_AEnemy_Statics; \
public: \
	DECLARE_CLASS(AEnemy, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceGame"), NO_API) \
	DECLARE_SERIALIZER(AEnemy)


#define SpaceGame_Source_SpaceGame_Enemy_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemy(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEnemy) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemy); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemy(AEnemy&&); \
	NO_API AEnemy(const AEnemy&); \
public:


#define SpaceGame_Source_SpaceGame_Enemy_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemy(AEnemy&&); \
	NO_API AEnemy(const AEnemy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemy)


#define SpaceGame_Source_SpaceGame_Enemy_h_12_PRIVATE_PROPERTY_OFFSET
#define SpaceGame_Source_SpaceGame_Enemy_h_9_PROLOG
#define SpaceGame_Source_SpaceGame_Enemy_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SpaceGame_Source_SpaceGame_Enemy_h_12_PRIVATE_PROPERTY_OFFSET \
	SpaceGame_Source_SpaceGame_Enemy_h_12_SPARSE_DATA \
	SpaceGame_Source_SpaceGame_Enemy_h_12_RPC_WRAPPERS \
	SpaceGame_Source_SpaceGame_Enemy_h_12_INCLASS \
	SpaceGame_Source_SpaceGame_Enemy_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SpaceGame_Source_SpaceGame_Enemy_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SpaceGame_Source_SpaceGame_Enemy_h_12_PRIVATE_PROPERTY_OFFSET \
	SpaceGame_Source_SpaceGame_Enemy_h_12_SPARSE_DATA \
	SpaceGame_Source_SpaceGame_Enemy_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	SpaceGame_Source_SpaceGame_Enemy_h_12_INCLASS_NO_PURE_DECLS \
	SpaceGame_Source_SpaceGame_Enemy_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SPACEGAME_API UClass* StaticClass<class AEnemy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SpaceGame_Source_SpaceGame_Enemy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
