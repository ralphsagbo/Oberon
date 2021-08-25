/*GENERATED BY OBNC 0.16.1*/

#include "ORB.h"
#include <obnc/Out.h>
#include <obnc/Files.h>
#include "ORS.h"
#include <obnc/OBNC.h>

#define OBERON_SOURCE_FILENAME "ORB.Mod"

const int ORB__ObjDesc_id;
const int *const ORB__ObjDesc_ids[1] = {&ORB__ObjDesc_id};
const OBNC_Td ORB__ObjDesc_td = {ORB__ObjDesc_ids, 1};

const int ORB__ModDesc_id;
const int *const ORB__ModDesc_ids[2] = {&ORB__ObjDesc_id, &ORB__ModDesc_id};
const OBNC_Td ORB__ModDesc_td = {ORB__ModDesc_ids, 2};

const int ORB__TypeDesc_id;
const int *const ORB__TypeDesc_ids[1] = {&ORB__TypeDesc_id};
const OBNC_Td ORB__TypeDesc_td = {ORB__TypeDesc_ids, 1};

ORB__Object_ ORB__topScope_, ORB__system_, ORB__OUT2_;
static ORB__Object_ universe_;

ORB__Type_ ORB__byteType_, ORB__boolType_, ORB__charType_;

ORB__Type_ ORB__intType_, ORB__realType_, ORB__setType_, ORB__nilType_, ORB__noType_, ORB__strType_;

static OBNC_INTEGER nofmod_, Ref_;

static ORB__Type_ typtab_[64];

void ORB__NewObj_(ORB__Object_ *obj_, const ORS__Ident_ id_, OBNC_INTEGER class_)
{
	ORB__Object_ new_ = 0, x_ = 0;

	x_ = ORB__topScope_;
	while (((*OBNC_PT(x_, 74)).next_ != 0) && (OBNC_CMP((*OBNC_PT((*OBNC_PT(x_, 74)).next_, 74)).name_, 32, id_, 32) != 0)) {
		x_ = (*OBNC_PT(x_, 74)).next_;
	}
	if ((*OBNC_PT(x_, 75)).next_ == 0) {
		OBNC_NEW(new_, &ORB__ObjDesc_td, struct ORB__ObjDesc_Heap, OBNC_REGULAR_ALLOC);
		OBNC_COPY_ARRAY(id_, (*OBNC_PT(new_, 76)).name_, 32);
		(*OBNC_PT(new_, 76)).class_ = (unsigned char) class_;
		(*OBNC_PT(new_, 76)).next_ = 0;
		(*OBNC_PT(new_, 76)).rdo_ = 0;
		(*OBNC_PT(new_, 76)).dsc_ = 0;
		(*OBNC_PT(x_, 77)).next_ = new_;
		(*obj_) = new_;
	}
	else {
		(*obj_) = (*OBNC_PT(x_, 78)).next_;
		ORS__Mark_("mult def", 9);
	}
}


ORB__Object_ ORB__thisObj_(void)
{
	ORB__Object_ s_ = 0, x_ = 0;

	s_ = ORB__topScope_;
	do {
		x_ = (*OBNC_PT(s_, 85)).next_;
		while ((x_ != 0) && (OBNC_CMP((*OBNC_PT(x_, 86)).name_, 32, ORS__id_, 32) != 0)) {
			x_ = (*OBNC_PT(x_, 86)).next_;
		}
		s_ = (*OBNC_PT(s_, 88)).dsc_;
	} while (! ((x_ != 0) || (s_ == 0)));
	return x_;
}


ORB__Object_ ORB__thisimport_(ORB__Object_ mod_)
{
	ORB__Object_ obj_ = 0;

	if ((*OBNC_PT(mod_, 95)).rdo_) {
		if ((*OBNC_PT(mod_, 96)).name_[0] != '\x00') {
			obj_ = (*OBNC_PT(mod_, 97)).dsc_;
			while ((obj_ != 0) && (OBNC_CMP((*OBNC_PT(obj_, 98)).name_, 32, ORS__id_, 32) != 0)) {
				obj_ = (*OBNC_PT(obj_, 98)).next_;
			}
		}
		else {
			obj_ = 0;
		}
	}
	else {
		obj_ = 0;
	}
	return obj_;
}


ORB__Object_ ORB__thisfield_(ORB__Type_ rec_)
{
	ORB__Object_ fld_ = 0;

	fld_ = (*OBNC_PT(rec_, 108)).dsc_;
	while ((fld_ != 0) && (OBNC_CMP((*OBNC_PT(fld_, 109)).name_, 32, ORS__id_, 32) != 0)) {
		fld_ = (*OBNC_PT(fld_, 109)).next_;
	}
	return fld_;
}


void ORB__OpenScope_(void)
{
	ORB__Object_ s_ = 0;

	OBNC_NEW(s_, &ORB__ObjDesc_td, struct ORB__ObjDesc_Heap, OBNC_REGULAR_ALLOC);
	(*OBNC_PT(s_, 115)).class_ = (unsigned char) 0;
	(*OBNC_PT(s_, 115)).dsc_ = ORB__topScope_;
	(*OBNC_PT(s_, 115)).next_ = 0;
	ORB__topScope_ = s_;
}


void ORB__CloseScope_(void)
{

	ORB__topScope_ = (*OBNC_PT(ORB__topScope_, 120)).dsc_;
}


void ORB__MakeFileName_(ORS__Ident_ FName_, const char name_[], OBNC_INTEGER name_len, const char ext_[], OBNC_INTEGER ext_len)
{
	OBNC_INTEGER i_, j_;

	i_ = 0;
	j_ = 0;
	while ((i_ < 27) && ((unsigned char) name_[OBNC_IT(i_, name_len, 127)] > (unsigned char) '\x00')) {
		FName_[OBNC_IT(i_, 32, 127)] = name_[OBNC_IT(i_, name_len, 127)];
		OBNC_INC(i_);
	}
	do {
		FName_[OBNC_IT(i_, 32, 128)] = ext_[OBNC_IT(j_, ext_len, 128)];
		OBNC_INC(i_);
		OBNC_INC(j_);
	} while (! (ext_[OBNC_IT(j_, ext_len, 128)] == '\x00'));
	FName_[OBNC_IT(i_, 32, 129)] = '\x00';
}


static ORB__Object_ ThisModule_(const ORS__Ident_ name_, const ORS__Ident_ orgname_, int non_, OBNC_INTEGER key_)
{
	ORB__Module_ mod_ = 0;
	ORB__Object_ obj_ = 0, obj1_ = 0;

	obj1_ = ORB__topScope_;
	obj_ = (*OBNC_PT(obj1_, 134)).next_;
	while ((obj_ != 0) && (OBNC_CMP((*OBNC_PT(obj_, 135)).name_, 32, name_, 32) != 0)) {
		obj1_ = obj_;
		obj_ = (*OBNC_PT(obj1_, 135)).next_;
	}
	if (obj_ == 0) {
		OBNC_NEW(mod_, &ORB__ModDesc_td, struct ORB__ModDesc_Heap, OBNC_REGULAR_ALLOC);
		(*((ORB__ObjDesc_ *) &(*OBNC_PT(mod_, 137)))).class_ = (unsigned char) 8;
		(*((ORB__ObjDesc_ *) &(*OBNC_PT(mod_, 137)))).rdo_ = 0;
		OBNC_COPY_ARRAY(name_, (*((ORB__ObjDesc_ *) &(*OBNC_PT(mod_, 138)))).name_, 32);
		OBNC_COPY_ARRAY(orgname_, (*OBNC_PT(mod_, 138)).orgname_, 32);
		(*((ORB__ObjDesc_ *) &(*OBNC_PT(mod_, 138)))).val_ = key_;
		(*((ORB__ObjDesc_ *) &(*OBNC_PT(mod_, 139)))).lev_ = nofmod_;
		OBNC_INC(nofmod_);
		(*((ORB__ObjDesc_ *) &(*OBNC_PT(mod_, 139)))).type_ = ORB__noType_;
		(*((ORB__ObjDesc_ *) &(*OBNC_PT(mod_, 139)))).dsc_ = 0;
		(*((ORB__ObjDesc_ *) &(*OBNC_PT(mod_, 139)))).next_ = 0;
		(*OBNC_PT(obj1_, 140)).next_ = (ORB__Object_) mod_;
		obj_ = (ORB__Object_) mod_;
	}
	else {
		if (non_) {
			ORS__Mark_("invalid import order", 21);
		}
	}
	return obj_;
}


static void Read_(Files__Rider_ *R_, const OBNC_Td *R_td, OBNC_INTEGER *x_)
{
	unsigned char b_;

	Files__Read_(&(*R_), R_td, &b_);
	if (b_ < 128) {
		(*x_) = b_;
	}
	else {
		(*x_) = b_ - 256;
	}
}


static void InType_(Files__Rider_ *R_, const OBNC_Td *R_td, ORB__Object_ thismod_, ORB__Type_ *T_)
{
	OBNC_INTEGER key_;
	OBNC_INTEGER ref_, class_, form_, np_, readonly_;
	ORB__Object_ fld_ = 0, par_ = 0, obj_ = 0, mod_ = 0;
	ORB__Type_ t_ = 0;
	ORS__Ident_ name_, modname_;

	Read_(&(*R_), R_td, &ref_);
	if (ref_ < 0) {
		(*T_) = typtab_[OBNC_IT(-ref_, 64, 160)];
	}
	else {
		OBNC_NEW(t_, &ORB__TypeDesc_td, struct ORB__TypeDesc_Heap, OBNC_REGULAR_ALLOC);
		(*T_) = t_;
		typtab_[OBNC_IT(ref_, 64, 161)] = t_;
		(*OBNC_PT(t_, 161)).mno_ = (*OBNC_PT(thismod_, 161)).lev_;
		Read_(&(*R_), R_td, &form_);
		(*OBNC_PT(t_, 162)).form_ = form_;
		if (form_ == 7) {
			InType_(&(*R_), R_td, thismod_, &(*OBNC_PT(t_, 163)).base_);
			(*OBNC_PT(t_, 163)).size_ = 4;
		}
		else if (form_ == 12) {
			InType_(&(*R_), R_td, thismod_, &(*OBNC_PT(t_, 165)).base_);
			Files__ReadNum_(&(*R_), R_td, &(*OBNC_PT(t_, 165)).len_);
			Files__ReadNum_(&(*R_), R_td, &(*OBNC_PT(t_, 165)).size_);
		}
		else if (form_ == 13) {
			InType_(&(*R_), R_td, thismod_, &(*OBNC_PT(t_, 167)).base_);
			if ((*OBNC_PT((*OBNC_PT(t_, 168)).base_, 168)).form_ == 9) {
				(*OBNC_PT(t_, 168)).base_ = 0;
				obj_ = 0;
			}
			else {
				obj_ = (*OBNC_PT((*OBNC_PT(t_, 168)).base_, 168)).dsc_;
			}
			Files__ReadNum_(&(*R_), R_td, &(*OBNC_PT(t_, 169)).len_);
			Files__ReadNum_(&(*R_), R_td, &(*OBNC_PT(t_, 170)).nofpar_);
			Files__ReadNum_(&(*R_), R_td, &(*OBNC_PT(t_, 171)).size_);
			Read_(&(*R_), R_td, &class_);
			while (class_ != 0) {
				OBNC_NEW(fld_, &ORB__ObjDesc_td, struct ORB__ObjDesc_Heap, OBNC_REGULAR_ALLOC);
				(*OBNC_PT(fld_, 174)).class_ = (unsigned char) class_;
				Files__ReadString_(&(*R_), R_td, (*OBNC_PT(fld_, 174)).name_, 32);
				if ((*OBNC_PT(fld_, 175)).name_[0] != '\x00') {
					(*OBNC_PT(fld_, 175)).expo_ = 1;
					InType_(&(*R_), R_td, thismod_, &(*OBNC_PT(fld_, 175)).type_);
				}
				else {
					(*OBNC_PT(fld_, 175)).expo_ = 0;
					(*OBNC_PT(fld_, 175)).type_ = ORB__nilType_;
				}
				Files__ReadNum_(&(*R_), R_td, &(*OBNC_PT(fld_, 176)).val_);
				(*OBNC_PT(fld_, 176)).next_ = obj_;
				obj_ = fld_;
				Read_(&(*R_), R_td, &class_);
			}
			(*OBNC_PT(t_, 178)).dsc_ = obj_;
		}
		else if (form_ == 10) {
			InType_(&(*R_), R_td, thismod_, &(*OBNC_PT(t_, 180)).base_);
			obj_ = 0;
			np_ = 0;
			Read_(&(*R_), R_td, &class_);
			while (class_ != 0) {
				OBNC_NEW(par_, &ORB__ObjDesc_td, struct ORB__ObjDesc_Heap, OBNC_REGULAR_ALLOC);
				(*OBNC_PT(par_, 183)).class_ = (unsigned char) class_;
				Read_(&(*R_), R_td, &readonly_);
				(*OBNC_PT(par_, 183)).rdo_ = readonly_ == 1;
				InType_(&(*R_), R_td, thismod_, &(*OBNC_PT(par_, 184)).type_);
				(*OBNC_PT(par_, 184)).next_ = obj_;
				obj_ = par_;
				OBNC_INC(np_);
				Read_(&(*R_), R_td, &class_);
			}
			(*OBNC_PT(t_, 186)).dsc_ = obj_;
			(*OBNC_PT(t_, 186)).nofpar_ = np_;
			(*OBNC_PT(t_, 186)).size_ = 4;
		}
		Files__ReadString_(&(*R_), R_td, modname_, 32);
		if (modname_[0] != '\x00') {
			Files__ReadInt_(&(*R_), R_td, &key_);
			Files__ReadString_(&(*R_), R_td, name_, 32);
			mod_ = ThisModule_(modname_, modname_, 0, key_);
			obj_ = (*OBNC_PT(mod_, 192)).dsc_;
			while ((obj_ != 0) && (OBNC_CMP((*OBNC_PT(obj_, 193)).name_, 32, name_, 32) != 0)) {
				obj_ = (*OBNC_PT(obj_, 193)).next_;
			}
			if (obj_ != 0) {
				(*T_) = (*OBNC_PT(obj_, 195)).type_;
			}
			else {
				OBNC_NEW(obj_, &ORB__ObjDesc_td, struct ORB__ObjDesc_Heap, OBNC_REGULAR_ALLOC);
				OBNC_COPY_ARRAY(name_, (*OBNC_PT(obj_, 196)).name_, 32);
				(*OBNC_PT(obj_, 196)).class_ = (unsigned char) 5;
				(*OBNC_PT(obj_, 196)).next_ = (*OBNC_PT(mod_, 196)).dsc_;
				(*OBNC_PT(mod_, 196)).dsc_ = obj_;
				(*OBNC_PT(obj_, 196)).type_ = t_;
				(*OBNC_PT(t_, 197)).mno_ = (*OBNC_PT(mod_, 197)).lev_;
				(*OBNC_PT(t_, 197)).typobj_ = obj_;
				(*T_) = t_;
			}
			typtab_[OBNC_IT(ref_, 64, 199)] = (*T_);
		}
	}
}


void ORB__Import_(ORS__Ident_ modid_, ORS__Ident_ modid1_)
{
	OBNC_INTEGER key_;
	OBNC_INTEGER class_, k_;
	ORB__Object_ obj_ = 0;
	ORB__Type_ t_ = 0;
	ORB__Object_ thismod_ = 0;
	ORS__Ident_ modname_, fname_;
	Files__File_ F_ = 0;
	Files__Rider_ R_;

	if (OBNC_CMP(modid1_, 32, "SYSTEM", 7) == 0) {
		thismod_ = ThisModule_(modid_, modid1_, 1, key_);
		OBNC_DEC(nofmod_);
		(*OBNC_PT(thismod_, 213)).lev_ = 0;
		(*OBNC_PT(thismod_, 213)).dsc_ = ORB__system_;
		(*OBNC_PT(thismod_, 213)).rdo_ = 1;
	}
	else if (OBNC_CMP(modid1_, 32, "Out2", 5) == 0) {
		thismod_ = ThisModule_(modid_, modid1_, 1, key_);
		OBNC_DEC(nofmod_);
		(*OBNC_PT(thismod_, 216)).lev_ = 0;
		(*OBNC_PT(thismod_, 216)).dsc_ = ORB__OUT2_;
		(*OBNC_PT(thismod_, 216)).rdo_ = 1;
	}
	else {
		ORB__MakeFileName_(fname_, modid1_, 32, ".smb", 5);
		F_ = Files__Old_(fname_, 32);
		if (F_ != 0) {
			Files__Set_(&R_, &Files__Rider_td, F_, 0);
			Files__ReadInt_(&R_, &Files__Rider_td, &key_);
			Files__ReadInt_(&R_, &Files__Rider_td, &key_);
			Files__ReadString_(&R_, &Files__Rider_td, modname_, 32);
			thismod_ = ThisModule_(modid_, modid1_, 1, key_);
			(*OBNC_PT(thismod_, 220)).rdo_ = 1;
			Read_(&R_, &Files__Rider_td, &class_);
			if (class_ != 1) {
				ORS__Mark_("wrong version", 14);
			}
			Read_(&R_, &Files__Rider_td, &class_);
			while (class_ != 0) {
				OBNC_NEW(obj_, &ORB__ObjDesc_td, struct ORB__ObjDesc_Heap, OBNC_REGULAR_ALLOC);
				(*OBNC_PT(obj_, 225)).class_ = (unsigned char) class_;
				Files__ReadString_(&R_, &Files__Rider_td, (*OBNC_PT(obj_, 225)).name_, 32);
				InType_(&R_, &Files__Rider_td, thismod_, &(*OBNC_PT(obj_, 226)).type_);
				(*OBNC_PT(obj_, 226)).lev_ = -(*OBNC_PT(thismod_, 226)).lev_;
				if (class_ == 5) {
					t_ = (*OBNC_PT(obj_, 228)).type_;
					(*OBNC_PT(t_, 228)).typobj_ = obj_;
					Read_(&R_, &Files__Rider_td, &k_);
					while (k_ != 0) {
						(*OBNC_PT(typtab_[OBNC_IT(k_, 64, 229)], 229)).base_ = t_;
						Read_(&R_, &Files__Rider_td, &k_);
					}
				}
				else {
					if (class_ == 1) {
						if ((*OBNC_PT((*OBNC_PT(obj_, 232)).type_, 232)).form_ == 5) {
							Files__ReadInt_(&R_, &Files__Rider_td, &(*OBNC_PT(obj_, 232)).val_);
						}
						else {
							Files__ReadNum_(&R_, &Files__Rider_td, &(*OBNC_PT(obj_, 232)).val_);
						}
					}
					else if (class_ == 2) {
						Files__ReadNum_(&R_, &Files__Rider_td, &(*OBNC_PT(obj_, 233)).val_);
						(*OBNC_PT(obj_, 233)).rdo_ = 1;
					}
				}
				(*OBNC_PT(obj_, 236)).next_ = (*OBNC_PT(thismod_, 236)).dsc_;
				(*OBNC_PT(thismod_, 236)).dsc_ = obj_;
				Read_(&R_, &Files__Rider_td, &class_);
			}
		}
		else {
			ORS__Mark_("import not available", 21);
		}
	}
}


static void OutType_(Files__Rider_ *R_, const OBNC_Td *R_td, ORB__Type_ t_);

static void OutType_OutPar_Local(Files__Rider_ *R_, const OBNC_Td *R_td, ORB__Object_ par_, OBNC_INTEGER n_)
{
	OBNC_INTEGER cl_;

	if (n_ > 0) {
		OutType_OutPar_Local(&(*R_), R_td, (*OBNC_PT(par_, 252)).next_, (n_ - 1));
		cl_ = (*OBNC_PT(par_, 252)).class_;
		Files__Write_(&(*R_), R_td, (unsigned char) cl_);
		if ((*OBNC_PT(par_, 254)).rdo_) {
			Files__Write_(&(*R_), R_td, (unsigned char) 1);
		}
		else {
			Files__Write_(&(*R_), R_td, (unsigned char) 0);
		}
		OutType_(&(*R_), R_td, (*OBNC_PT(par_, 255)).type_);
	}
}


static void OutType_FindHiddenPointers_Local(Files__Rider_ *R_, const OBNC_Td *R_td, ORB__Type_ typ_, OBNC_INTEGER offset_)
{
	ORB__Object_ fld_ = 0;
	OBNC_INTEGER i_, n_;

	if (((*OBNC_PT(typ_, 262)).form_ == 7) || ((*OBNC_PT(typ_, 262)).form_ == 8)) {
		Files__Write_(&(*R_), R_td, (unsigned char) 4);
		Files__Write_(&(*R_), R_td, (unsigned char) 0);
		Files__WriteNum_(&(*R_), R_td, offset_);
	}
	else if ((*OBNC_PT(typ_, 263)).form_ == 13) {
		fld_ = (*OBNC_PT(typ_, 263)).dsc_;
		while (fld_ != 0) {
			OutType_FindHiddenPointers_Local(&(*R_), R_td, (*OBNC_PT(fld_, 264)).type_, ((*OBNC_PT(fld_, 264)).val_ + offset_));
			fld_ = (*OBNC_PT(fld_, 264)).next_;
		}
	}
	else if ((*OBNC_PT(typ_, 265)).form_ == 12) {
		i_ = 0;
		n_ = (*OBNC_PT(typ_, 265)).len_;
		while (i_ < n_) {
			OutType_FindHiddenPointers_Local(&(*R_), R_td, (*OBNC_PT(typ_, 266)).base_, (((*OBNC_PT((*OBNC_PT(typ_, 266)).base_, 266)).size_ * i_) + offset_));
			OBNC_INC(i_);
		}
	}
}


static void OutType_(Files__Rider_ *R_, const OBNC_Td *R_td, ORB__Type_ t_)
{
	ORB__Object_ obj_ = 0, mod_ = 0, fld_ = 0;

	if ((*OBNC_PT(t_, 271)).ref_ > 0) {
		Files__Write_(&(*R_), R_td, (unsigned char) (-(*OBNC_PT(t_, 271)).ref_));
	}
	else {
		obj_ = (*OBNC_PT(t_, 272)).typobj_;
		if (obj_ != 0) {
			Files__Write_(&(*R_), R_td, (unsigned char) Ref_);
			(*OBNC_PT(t_, 273)).ref_ = Ref_;
			OBNC_INC(Ref_);
		}
		else {
			Files__Write_(&(*R_), R_td, (unsigned char) 0);
		}
		Files__Write_(&(*R_), R_td, (unsigned char) (*OBNC_PT(t_, 274)).form_);
		if ((*OBNC_PT(t_, 275)).form_ == 7) {
			OutType_(&(*R_), R_td, (*OBNC_PT(t_, 275)).base_);
		}
		else if ((*OBNC_PT(t_, 276)).form_ == 12) {
			OutType_(&(*R_), R_td, (*OBNC_PT(t_, 276)).base_);
			Files__WriteNum_(&(*R_), R_td, (*OBNC_PT(t_, 276)).len_);
			Files__WriteNum_(&(*R_), R_td, (*OBNC_PT(t_, 276)).size_);
		}
		else if ((*OBNC_PT(t_, 277)).form_ == 13) {
			if ((*OBNC_PT(t_, 278)).base_ != 0) {
				OutType_(&(*R_), R_td, (*OBNC_PT(t_, 278)).base_);
			}
			else {
				OutType_(&(*R_), R_td, ORB__noType_);
			}
			if (obj_ != 0) {
				Files__WriteNum_(&(*R_), R_td, (*OBNC_PT(obj_, 279)).exno_);
			}
			else {
				Files__Write_(&(*R_), R_td, (unsigned char) 0);
			}
			Files__WriteNum_(&(*R_), R_td, (*OBNC_PT(t_, 280)).nofpar_);
			Files__WriteNum_(&(*R_), R_td, (*OBNC_PT(t_, 280)).size_);
			fld_ = (*OBNC_PT(t_, 281)).dsc_;
			while (fld_ != 0) {
				if ((*OBNC_PT(fld_, 283)).expo_) {
					Files__Write_(&(*R_), R_td, (unsigned char) 4);
					Files__WriteString_(&(*R_), R_td, (*OBNC_PT(fld_, 284)).name_, 32);
					OutType_(&(*R_), R_td, (*OBNC_PT(fld_, 284)).type_);
					Files__WriteNum_(&(*R_), R_td, (*OBNC_PT(fld_, 284)).val_);
				}
				else {
					OutType_FindHiddenPointers_Local(&(*R_), R_td, (*OBNC_PT(fld_, 285)).type_, (*OBNC_PT(fld_, 285)).val_);
				}
				fld_ = (*OBNC_PT(fld_, 288)).next_;
			}
			Files__Write_(&(*R_), R_td, (unsigned char) 0);
		}
		else if ((*OBNC_PT(t_, 290)).form_ == 10) {
			OutType_(&(*R_), R_td, (*OBNC_PT(t_, 290)).base_);
			OutType_OutPar_Local(&(*R_), R_td, (*OBNC_PT(t_, 290)).dsc_, (*OBNC_PT(t_, 290)).nofpar_);
			Files__Write_(&(*R_), R_td, (unsigned char) 0);
		}
		if (((*OBNC_PT(t_, 292)).mno_ > 0) && (obj_ != 0)) {
			mod_ = (*OBNC_PT(ORB__topScope_, 293)).next_;
			while ((mod_ != 0) && ((*OBNC_PT(mod_, 294)).lev_ != (*OBNC_PT(t_, 294)).mno_)) {
				mod_ = (*OBNC_PT(mod_, 294)).next_;
			}
			if (mod_ != 0) {
				Files__WriteString_(&(*R_), R_td, (*OBNC_PT((*((ORB__Module_*) OBNC_PTT(&(mod_), OBNC_TD(mod_, struct ORB__ModDesc_Heap), &ORB__ModDesc_id, 1, 295))), 295)).orgname_, 32);
				Files__WriteInt_(&(*R_), R_td, (*OBNC_PT(mod_, 295)).val_);
				Files__WriteString_(&(*R_), R_td, (*OBNC_PT(obj_, 295)).name_, 32);
			}
			else {
				ORS__Mark_("re-export not found", 20);
				Files__Write_(&(*R_), R_td, (unsigned char) 0);
			}
		}
		else {
			Files__Write_(&(*R_), R_td, (unsigned char) 0);
		}
	}
}


void ORB__Export_(ORS__Ident_ modid_, int *newSF_, OBNC_INTEGER *key_)
{
	OBNC_INTEGER x_, sum_, oldkey_;
	ORB__Object_ obj_ = 0, obj0_ = 0;
	ORS__Ident_ filename_;
	Files__File_ F_ = 0, F1_ = 0;
	Files__Rider_ R_, R1_;

	Ref_ = 14;
	ORB__MakeFileName_(filename_, modid_, 32, ".smb", 5);
	Out__String_("Exporting to file ", 19);
	Out__String_(filename_, 32);
	Out__Ln_();
	F_ = Files__New_(filename_, 32);
	Files__Set_(&R_, &Files__Rider_td, F_, 0);
	Files__WriteInt_(&R_, &Files__Rider_td, 0);
	Files__WriteInt_(&R_, &Files__Rider_td, 0);
	Files__WriteString_(&R_, &Files__Rider_td, modid_, 32);
	Files__Write_(&R_, &Files__Rider_td, (unsigned char) 1);
	obj_ = (*OBNC_PT(ORB__topScope_, 314)).next_;
	while (obj_ != 0) {
		if ((*OBNC_PT(obj_, 316)).expo_) {
			Files__Write_(&R_, &Files__Rider_td, (*OBNC_PT(obj_, 317)).class_);
			Files__WriteString_(&R_, &Files__Rider_td, (*OBNC_PT(obj_, 317)).name_, 32);
			OutType_(&R_, &Files__Rider_td, (*OBNC_PT(obj_, 318)).type_);
			if ((*OBNC_PT(obj_, 319)).class_ == 5) {
				if ((*OBNC_PT((*OBNC_PT(obj_, 320)).type_, 320)).form_ == 13) {
					obj0_ = (*OBNC_PT(ORB__topScope_, 321)).next_;
					while (obj0_ != obj_) {
						if ((((*OBNC_PT((*OBNC_PT(obj0_, 323)).type_, 323)).form_ == 7) && ((*OBNC_PT((*OBNC_PT(obj0_, 323)).type_, 323)).base_ == (*OBNC_PT(obj_, 323)).type_)) && ((*OBNC_PT((*OBNC_PT(obj0_, 323)).type_, 323)).ref_ > 0)) {
							Files__Write_(&R_, &Files__Rider_td, (unsigned char) (*OBNC_PT((*OBNC_PT(obj0_, 323)).type_, 323)).ref_);
						}
						obj0_ = (*OBNC_PT(obj0_, 325)).next_;
					}
				}
				Files__Write_(&R_, &Files__Rider_td, (unsigned char) 0);
			}
			else if ((*OBNC_PT(obj_, 328)).class_ == 1) {
				if ((*OBNC_PT((*OBNC_PT(obj_, 329)).type_, 329)).form_ == 5) {
					Files__WriteInt_(&R_, &Files__Rider_td, (*OBNC_PT(obj_, 329)).val_);
				}
				else {
					Files__WriteNum_(&R_, &Files__Rider_td, (*OBNC_PT(obj_, 330)).val_);
				}
			}
			else if ((*OBNC_PT(obj_, 332)).class_ == 2) {
				Files__WriteNum_(&R_, &Files__Rider_td, (*OBNC_PT(obj_, 332)).val_);
			}
		}
		obj_ = (*OBNC_PT(obj_, 336)).next_;
	}
	do {
		Files__Write_(&R_, &Files__Rider_td, (unsigned char) 0);
	} while (! ((OBNC_Mod(Files__Length_(F_), 4)) == 0));
	for (Ref_ = 14; Ref_ <= 63; Ref_ += 1) {
		typtab_[OBNC_IT(Ref_, 64, 338)] = 0;
	}
	Files__Set_(&R_, &Files__Rider_td, F_, 0);
	sum_ = 0;
	Files__ReadInt_(&R_, &Files__Rider_td, &x_);
	while (! R_.eof_) {
		sum_ = sum_ + x_;
		Files__ReadInt_(&R_, &Files__Rider_td, &x_);
	}
	F1_ = Files__Old_(filename_, 32);
	if (F1_ != 0) {
		Files__Set_(&R1_, &Files__Rider_td, F1_, 4);
		Files__ReadInt_(&R1_, &Files__Rider_td, &oldkey_);
	}
	else {
		oldkey_ = sum_ + 1;
	}
	if (sum_ != oldkey_) {
		if ((*newSF_) || (F1_ == 0)) {
			(*key_) = sum_;
			(*newSF_) = 1;
			Files__Set_(&R_, &Files__Rider_td, F_, 4);
			Files__WriteInt_(&R_, &Files__Rider_td, sum_);
			Files__Register_(F_);
			Files__Close_(F_);
		}
		else {
			ORS__Mark_("new symbol file inhibited", 26);
		}
	}
	else {
		(*newSF_) = 0;
		(*key_) = sum_;
	}
}


void ORB__Init_(void)
{

	ORB__topScope_ = universe_;
	nofmod_ = 1;
}


static ORB__Type_ type_(OBNC_INTEGER ref_, OBNC_INTEGER form_, OBNC_INTEGER size_)
{
	ORB__Type_ tp_ = 0;

	OBNC_NEW(tp_, &ORB__TypeDesc_td, struct ORB__TypeDesc_Heap, OBNC_REGULAR_ALLOC);
	(*OBNC_PT(tp_, 358)).form_ = form_;
	(*OBNC_PT(tp_, 358)).size_ = size_;
	(*OBNC_PT(tp_, 358)).ref_ = ref_;
	(*OBNC_PT(tp_, 358)).base_ = 0;
	typtab_[OBNC_IT(ref_, 64, 359)] = tp_;
	return tp_;
}


static void enter_(const char name_[], OBNC_INTEGER name_len, OBNC_INTEGER cl_, ORB__Type_ type_, OBNC_INTEGER n_)
{
	ORB__Object_ obj_ = 0;

	OBNC_NEW(obj_, &ORB__ObjDesc_td, struct ORB__ObjDesc_Heap, OBNC_REGULAR_ALLOC);
	OBNC_AAT(name_len, 32, 364);
	OBNC_COPY_ARRAY(name_, (*OBNC_PT(obj_, 364)).name_, name_len);
	(*OBNC_PT(obj_, 364)).class_ = (unsigned char) cl_;
	(*OBNC_PT(obj_, 364)).type_ = type_;
	(*OBNC_PT(obj_, 364)).val_ = n_;
	(*OBNC_PT(obj_, 364)).dsc_ = 0;
	if (cl_ == 5) {
		(*OBNC_PT(type_, 365)).typobj_ = obj_;
	}
	(*OBNC_PT(obj_, 366)).next_ = ORB__system_;
	ORB__system_ = obj_;
}


static void enterPerso_(ORB__Object_ *domain_, const char name_[], OBNC_INTEGER name_len, OBNC_INTEGER cl_, ORB__Type_ type_, OBNC_INTEGER n_)
{
	ORB__Object_ obj_ = 0;

	OBNC_NEW(obj_, &ORB__ObjDesc_td, struct ORB__ObjDesc_Heap, OBNC_REGULAR_ALLOC);
	OBNC_AAT(name_len, 32, 371);
	OBNC_COPY_ARRAY(name_, (*OBNC_PT(obj_, 371)).name_, name_len);
	(*OBNC_PT(obj_, 371)).class_ = (unsigned char) cl_;
	(*OBNC_PT(obj_, 371)).type_ = type_;
	(*OBNC_PT(obj_, 371)).val_ = n_;
	(*OBNC_PT(obj_, 371)).dsc_ = 0;
	if (cl_ == 5) {
		(*OBNC_PT(type_, 372)).typobj_ = obj_;
	}
	(*OBNC_PT(obj_, 373)).next_ = (*domain_);
	(*domain_) = obj_;
}


void ORB__Init(void)
{
	static int initialized = 0;

	if (! initialized) {
		Out__Init();
		Files__Init();
		ORS__Init();
		ORB__byteType_ = type_(1, 4, 1);
		ORB__boolType_ = type_(2, 2, 1);
		ORB__charType_ = type_(3, 3, 1);
		ORB__intType_ = type_(4, 4, 4);
		ORB__realType_ = type_(5, 5, 4);
		ORB__setType_ = type_(6, 6, 4);
		ORB__nilType_ = type_(8, 8, 4);
		ORB__noType_ = type_(9, 9, 4);
		ORB__strType_ = type_(11, 11, 8);
		ORB__system_ = 0;
		enter_("UML", 4, 7, ORB__intType_, 132);
		enter_("SBC", 4, 7, ORB__intType_, 122);
		enter_("ADC", 4, 7, ORB__intType_, 112);
		enter_("ROR", 4, 7, ORB__intType_, 92);
		enter_("ASR", 4, 7, ORB__intType_, 82);
		enter_("LSL", 4, 7, ORB__intType_, 72);
		enter_("LEN", 4, 7, ORB__intType_, 61);
		enter_("CHR", 4, 7, ORB__charType_, 51);
		enter_("ORD", 4, 7, ORB__intType_, 41);
		enter_("FLT", 4, 7, ORB__realType_, 31);
		enter_("FLOOR", 6, 7, ORB__intType_, 21);
		enter_("ODD", 4, 7, ORB__boolType_, 11);
		enter_("ABS", 4, 7, ORB__intType_, 1);
		enter_("LSR", 4, 7, ORB__intType_, 142);
		enter_("UNPK", 5, 6, ORB__noType_, 72);
		enter_("PACK", 5, 6, ORB__noType_, 62);
		enter_("NEW", 4, 6, ORB__noType_, 51);
		enter_("ASSERT", 7, 6, ORB__noType_, 41);
		enter_("EXCL", 5, 6, ORB__noType_, 32);
		enter_("INCL", 5, 6, ORB__noType_, 22);
		enter_("DEC", 4, 6, ORB__noType_, 11);
		enter_("INC", 4, 6, ORB__noType_, 1);
		enter_("SET", 4, 5, ORB__setType_, 0);
		enter_("BOOLEAN", 8, 5, ORB__boolType_, 0);
		enter_("BYTE", 5, 5, ORB__byteType_, 0);
		enter_("CHAR", 5, 5, ORB__charType_, 0);
		enter_("LONGREAL", 9, 5, ORB__realType_, 0);
		enter_("REAL", 5, 5, ORB__realType_, 0);
		enter_("INTEGER", 8, 5, ORB__intType_, 0);
		ORB__topScope_ = 0;
		ORB__OpenScope_();
		(*OBNC_PT(ORB__topScope_, 423)).next_ = ORB__system_;
		universe_ = ORB__topScope_;
		ORB__system_ = 0;
		enter_("CALL", 5, 7, ORB__intType_, 192);
		enter_("SIZE", 5, 7, ORB__intType_, 181);
		enter_("ADR", 4, 7, ORB__intType_, 171);
		enter_("VAL", 4, 7, ORB__intType_, 162);
		enter_("BIT", 4, 7, ORB__boolType_, 152);
		enter_("COPY", 5, 6, ORB__noType_, 123);
		enter_("PUT", 4, 6, ORB__noType_, 112);
		enter_("GET", 4, 6, ORB__noType_, 102);
		ORB__OUT2_ = 0;
		enterPerso_(&ORB__OUT2_, "Char", 5, 6, ORB__noType_, 131);
		enterPerso_(&ORB__OUT2_, "String", 7, 6, ORB__noType_, 141);
		enterPerso_(&ORB__OUT2_, "StringLn", 9, 6, ORB__noType_, 151);
		enterPerso_(&ORB__OUT2_, "Int", 4, 6, ORB__noType_, 161);
		enterPerso_(&ORB__OUT2_, "Hex", 4, 6, ORB__noType_, 171);
		enterPerso_(&ORB__OUT2_, "Real", 5, 6, ORB__noType_, 181);
		enterPerso_(&ORB__OUT2_, "Ln", 3, 6, ORB__noType_, 190);
		initialized = 1;
	}
}