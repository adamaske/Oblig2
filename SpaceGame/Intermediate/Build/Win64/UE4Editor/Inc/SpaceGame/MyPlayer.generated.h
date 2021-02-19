// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SPACEGAME_MyPlayer_generated_h
#error "MyPlayer.generated.h already included, missing '#pragma once' in MyPlayer.h"
#endif
#define SPACEGAME_MyPlayer_generated_h

#define SpaceGame_Source_SpaceGame_MyPlayer_h_13_SPARSE_DATA
#define SpaceGame_Source_SpaceGame_MyPlayer_h_13_RPC_WRAPPERS
#define SpaceGame_Source_SpaceGame_MyPlayer_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define SpaceGame_Source_SpaceGame_MyPlayer_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyPlayer(); \
	friend struct Z_Construct_UClass_AMyPlayer_Statics; \
public: \
	DECLARE_CLASS(AMyPlayer, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceGame"), NO_API) \
	DECLARE_SERIALIZER(AMyPlayer)


#define SpaceGame_Source_SpaceGame_MyPlayer_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAMyPlayer(); \
	friend struct Z_Construct_UClass_AMyPlayer_Statics; \
public: \
	DECLARE_CLASS(AMyPlayer, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceGame"), NO_API) \
	DECLARE_SERIALIZER(AMyPlayer)


#define SpaceGame_Source_SpaceGame_MyPlayer_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyPlayer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyPlayer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyPlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyPlayer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyPlayer(AMyPlayer&&); \
	NO_API AMyPlayer(const AMyPlayer&); \
public:


#define SpaceGame_Source_SpaceGame_MyPlayer_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyPlayer(AMyPlayer&&); \
	NO_API AMyPlayer(const AMyPlayer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyPlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyPlayer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyPlayer)


#define SpaceGame_Source_SpaceGame_MyPlayer_h_13_PRIVATE_PROPERTY_OFFSET
#define SpaceGame_Source_SpaceGame_MyPlayer_h_10_PROLOG
#define SpaceGame_Source_SpaceGame_MyPlayer_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SpaceGame_Source_SpaceGame_MyPlayer_h_13_PRIVATE_PROPERTY_OFFSET \
	SpaceGame_Source_SpaceGame_MyPlayer_h_13_SPARSE_DATA \
	SpaceGame_Source_SpaceGame_MyPlayer_h_13_RPC_WRAPPERS \
	SpaceGame_Source_SpaceGame_MyPlayer_h_13_INCLASS \
	SpaceGame_Source_SpaceGame_MyPlayer_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SpaceGame_Source_SpaceGame_MyPlayer_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SpaceGame_Source_SpaceGame_MyPlayer_h_13_PRIVATE_PROPERTY_OFFSET \
	SpaceGame_Source_SpaceGame_MyPlayer_h_13_SPARSE_DATA \
	SpaceGame_Source_SpaceGame_MyPlayer_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	SpaceGame_Source_SpaceGame_MyPlayer_h_13_INCLASS_NO_PURE_DECLS \
	SpaceGame_Source_SpaceGame_MyPlayer_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SPACEGAME_API UClass* StaticClass<class AMyPlayer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SpaceGame_Source_SpaceGame_MyPlayer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
