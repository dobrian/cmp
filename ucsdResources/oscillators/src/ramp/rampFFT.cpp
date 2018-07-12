/* ------------------------------------------------------------
name: "rampFFT"
Code generated with Faust 2.6.5 (https://faust.grame.fr)
Compilation options: cpp, -scal -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

/************************************************************************

	IMPORTANT NOTE : this file contains two clearly delimited sections : 
	the ARCHITECTURE section (in two parts) and the USER section. Each section 
	is governed by its own copyright and license. Please check individually 
	each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it 
    and/or modify it under the terms of the GNU General Public License 
    as published by the Free Software Foundation; either version 3 of 
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License 
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work 
    that contains this FAUST architecture section and distribute  
    that work under terms of your choice, so long as this FAUST 
    architecture section is not modified. 

 ************************************************************************
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <string>
#include <map>
#include <iostream> 

#include "faust/gui/console.h"
#include "faust/dsp/dsp.h"
#include "faust/misc.h"
#include "faust/audio/channels.h"

/******************************************************************************
*******************************************************************************

							       VECTOR INTRINSICS

*******************************************************************************
*******************************************************************************/

		
/********************END ARCHITECTURE SECTION (part 1/2)****************/

/**************************BEGIN USER SECTION **************************/
		
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>

float mydsp_faustpower2_f(float value) {
	return (value * value);
	
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 private:
	
	float fRec0[2];
	int IOTA;
	float fVec0[64];
	int fSamplingFreq;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("filename", "rampFFT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "rampFFT");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
	}

	virtual int getNumInputs() {
		return 0;
		
	}
	virtual int getNumOutputs() {
		return 33;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			case 2: {
				rate = 1;
				break;
			}
			case 3: {
				rate = 1;
				break;
			}
			case 4: {
				rate = 1;
				break;
			}
			case 5: {
				rate = 1;
				break;
			}
			case 6: {
				rate = 1;
				break;
			}
			case 7: {
				rate = 1;
				break;
			}
			case 8: {
				rate = 1;
				break;
			}
			case 9: {
				rate = 1;
				break;
			}
			case 10: {
				rate = 1;
				break;
			}
			case 11: {
				rate = 1;
				break;
			}
			case 12: {
				rate = 1;
				break;
			}
			case 13: {
				rate = 1;
				break;
			}
			case 14: {
				rate = 1;
				break;
			}
			case 15: {
				rate = 1;
				break;
			}
			case 16: {
				rate = 1;
				break;
			}
			case 17: {
				rate = 1;
				break;
			}
			case 18: {
				rate = 1;
				break;
			}
			case 19: {
				rate = 1;
				break;
			}
			case 20: {
				rate = 1;
				break;
			}
			case 21: {
				rate = 1;
				break;
			}
			case 22: {
				rate = 1;
				break;
			}
			case 23: {
				rate = 1;
				break;
			}
			case 24: {
				rate = 1;
				break;
			}
			case 25: {
				rate = 1;
				break;
			}
			case 26: {
				rate = 1;
				break;
			}
			case 27: {
				rate = 1;
				break;
			}
			case 28: {
				rate = 1;
				break;
			}
			case 29: {
				rate = 1;
				break;
			}
			case 30: {
				rate = 1;
				break;
			}
			case 31: {
				rate = 1;
				break;
			}
			case 32: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		
	}
	
	virtual void instanceResetUserInterface() {
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
			
		}
		IOTA = 0;
		for (int l1 = 0; (l1 < 64); l1 = (l1 + 1)) {
			fVec0[l1] = 0.0f;
			
		}
		
	}
	
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("rampFFT");
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		FAUSTFLOAT* output2 = outputs[2];
		FAUSTFLOAT* output3 = outputs[3];
		FAUSTFLOAT* output4 = outputs[4];
		FAUSTFLOAT* output5 = outputs[5];
		FAUSTFLOAT* output6 = outputs[6];
		FAUSTFLOAT* output7 = outputs[7];
		FAUSTFLOAT* output8 = outputs[8];
		FAUSTFLOAT* output9 = outputs[9];
		FAUSTFLOAT* output10 = outputs[10];
		FAUSTFLOAT* output11 = outputs[11];
		FAUSTFLOAT* output12 = outputs[12];
		FAUSTFLOAT* output13 = outputs[13];
		FAUSTFLOAT* output14 = outputs[14];
		FAUSTFLOAT* output15 = outputs[15];
		FAUSTFLOAT* output16 = outputs[16];
		FAUSTFLOAT* output17 = outputs[17];
		FAUSTFLOAT* output18 = outputs[18];
		FAUSTFLOAT* output19 = outputs[19];
		FAUSTFLOAT* output20 = outputs[20];
		FAUSTFLOAT* output21 = outputs[21];
		FAUSTFLOAT* output22 = outputs[22];
		FAUSTFLOAT* output23 = outputs[23];
		FAUSTFLOAT* output24 = outputs[24];
		FAUSTFLOAT* output25 = outputs[25];
		FAUSTFLOAT* output26 = outputs[26];
		FAUSTFLOAT* output27 = outputs[27];
		FAUSTFLOAT* output28 = outputs[28];
		FAUSTFLOAT* output29 = outputs[29];
		FAUSTFLOAT* output30 = outputs[30];
		FAUSTFLOAT* output31 = outputs[31];
		FAUSTFLOAT* output32 = outputs[32];
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec0[0] = std::fmod((fRec0[1] + 0.0125000002f), 1.0f);
			float fTemp0 = (2.0f * fRec0[0]);
			float fTemp1 = (fTemp0 + -1.0f);
			fVec0[(IOTA & 63)] = fTemp1;
			float fTemp2 = (fTemp0 + fVec0[((IOTA - 32) & 63)]);
			float fTemp3 = (fVec0[((IOTA - 48) & 63)] + (fTemp2 + fVec0[((IOTA - 16) & 63)]));
			float fTemp4 = (fVec0[((IOTA - 56) & 63)] + (fVec0[((IOTA - 24) & 63)] + (fVec0[((IOTA - 40) & 63)] + (fTemp3 + fVec0[((IOTA - 8) & 63)]))));
			float fTemp5 = (fVec0[((IOTA - 60) & 63)] + (fVec0[((IOTA - 28) & 63)] + (fVec0[((IOTA - 44) & 63)] + (fVec0[((IOTA - 12) & 63)] + (fVec0[((IOTA - 52) & 63)] + (fVec0[((IOTA - 20) & 63)] + (fVec0[((IOTA - 36) & 63)] + (fTemp4 + fVec0[((IOTA - 4) & 63)]))))))));
			float fTemp6 = (fVec0[((IOTA - 62) & 63)] + (fVec0[((IOTA - 30) & 63)] + (fVec0[((IOTA - 46) & 63)] + (fVec0[((IOTA - 14) & 63)] + (fVec0[((IOTA - 54) & 63)] + (fVec0[((IOTA - 22) & 63)] + (fVec0[((IOTA - 38) & 63)] + (fVec0[((IOTA - 6) & 63)] + (fVec0[((IOTA - 58) & 63)] + (fVec0[((IOTA - 26) & 63)] + (fVec0[((IOTA - 42) & 63)] + (fVec0[((IOTA - 10) & 63)] + (fVec0[((IOTA - 50) & 63)] + (fVec0[((IOTA - 18) & 63)] + (fVec0[((IOTA - 34) & 63)] + (fTemp5 + fVec0[((IOTA - 2) & 63)]))))))))))))))));
			output0[i] = FAUSTFLOAT(mydsp_faustpower2_f(std::fabs(((fVec0[((IOTA - 63) & 63)] + (fVec0[((IOTA - 31) & 63)] + (fVec0[((IOTA - 47) & 63)] + (fVec0[((IOTA - 15) & 63)] + (fVec0[((IOTA - 55) & 63)] + (fVec0[((IOTA - 23) & 63)] + (fVec0[((IOTA - 39) & 63)] + (fVec0[((IOTA - 7) & 63)] + (fVec0[((IOTA - 59) & 63)] + (fVec0[((IOTA - 27) & 63)] + (fVec0[((IOTA - 43) & 63)] + (fVec0[((IOTA - 11) & 63)] + (fVec0[((IOTA - 51) & 63)] + (fVec0[((IOTA - 19) & 63)] + (fVec0[((IOTA - 35) & 63)] + (fVec0[((IOTA - 3) & 63)] + (fVec0[((IOTA - 61) & 63)] + (fVec0[((IOTA - 29) & 63)] + (fVec0[((IOTA - 45) & 63)] + (fVec0[((IOTA - 13) & 63)] + (fVec0[((IOTA - 53) & 63)] + (fVec0[((IOTA - 21) & 63)] + (fVec0[((IOTA - 37) & 63)] + (fVec0[((IOTA - 5) & 63)] + (fVec0[((IOTA - 57) & 63)] + (fVec0[((IOTA - 25) & 63)] + (fVec0[((IOTA - 41) & 63)] + (fVec0[((IOTA - 9) & 63)] + (fVec0[((IOTA - 49) & 63)] + (fVec0[((IOTA - 17) & 63)] + (fVec0[((IOTA - 33) & 63)] + (fTemp6 + fVec0[((IOTA - 1) & 63)])))))))))))))))))))))))))))))))) + -1.0f))));
			float fTemp7 = (fVec0[((IOTA - 25) & 63)] - fVec0[((IOTA - 57) & 63)]);
			float fTemp8 = (0.0f - fTemp7);
			float fTemp9 = (fVec0[((IOTA - 49) & 63)] + (0.707106769f * fTemp8));
			float fTemp10 = (fVec0[((IOTA - 29) & 63)] - fVec0[((IOTA - 61) & 63)]);
			float fTemp11 = (0.0f - fTemp10);
			float fTemp12 = (fVec0[((IOTA - 13) & 63)] - fVec0[((IOTA - 45) & 63)]);
			float fTemp13 = (0.707106769f * fTemp12);
			float fTemp14 = ((fVec0[((IOTA - 53) & 63)] + (0.707106769f * fTemp11)) - (fVec0[((IOTA - 21) & 63)] + fTemp13));
			float fTemp15 = (fTemp9 + (0.923879504f * fTemp14));
			float fTemp16 = (fVec0[((IOTA - 27) & 63)] - fVec0[((IOTA - 59) & 63)]);
			float fTemp17 = (0.0f - fTemp16);
			float fTemp18 = (fVec0[((IOTA - 51) & 63)] + (0.707106769f * fTemp17));
			float fTemp19 = (fVec0[((IOTA - 31) & 63)] - fVec0[((IOTA - 63) & 63)]);
			float fTemp20 = (0.0f - fTemp19);
			float fTemp21 = (fVec0[((IOTA - 15) & 63)] - fVec0[((IOTA - 47) & 63)]);
			float fTemp22 = (0.707106769f * fTemp21);
			float fTemp23 = ((fVec0[((IOTA - 55) & 63)] + (0.707106769f * fTemp20)) - (fVec0[((IOTA - 23) & 63)] + fTemp22));
			float fTemp24 = (fVec0[((IOTA - 11) & 63)] - fVec0[((IOTA - 43) & 63)]);
			float fTemp25 = (0.707106769f * fTemp24);
			float fTemp26 = (fVec0[((IOTA - 19) & 63)] + fTemp25);
			float fTemp27 = (0.707106769f * fTemp20);
			float fTemp28 = (0.707106769f * fTemp21);
			float fTemp29 = ((fTemp27 + (fVec0[((IOTA - 7) & 63)] + fTemp28)) - fVec0[((IOTA - 39) & 63)]);
			float fTemp30 = ((fTemp18 + (0.923879504f * fTemp23)) - (fTemp26 + (0.382683426f * fTemp29)));
			float fTemp31 = (0.980785251f * fTemp30);
			float fTemp32 = (fVec0[((IOTA - 9) & 63)] - fVec0[((IOTA - 41) & 63)]);
			float fTemp33 = (0.707106769f * fTemp32);
			float fTemp34 = (fVec0[((IOTA - 17) & 63)] + fTemp33);
			float fTemp35 = (0.707106769f * fTemp11);
			float fTemp36 = (0.707106769f * fTemp12);
			float fTemp37 = ((fTemp35 + (fVec0[((IOTA - 5) & 63)] + fTemp36)) - fVec0[((IOTA - 37) & 63)]);
			float fTemp38 = (fTemp34 + (0.382683426f * fTemp37));
			float fTemp39 = (0.707106769f * fTemp17);
			float fTemp40 = (0.707106769f * fTemp24);
			float fTemp41 = (fTemp39 + (fVec0[((IOTA - 3) & 63)] + fTemp40));
			float fTemp42 = (((0.382683426f * fTemp23) + (fTemp41 + (0.923879504f * fTemp29))) - fVec0[((IOTA - 35) & 63)]);
			float fTemp43 = ((fTemp15 + fTemp31) - (fTemp38 + (0.195090324f * fTemp42)));
			float fTemp44 = (fVec0[((IOTA - 26) & 63)] - fVec0[((IOTA - 58) & 63)]);
			float fTemp45 = (0.0f - fTemp44);
			float fTemp46 = (fVec0[((IOTA - 50) & 63)] + (0.707106769f * fTemp45));
			float fTemp47 = (fVec0[((IOTA - 30) & 63)] - fVec0[((IOTA - 62) & 63)]);
			float fTemp48 = (0.0f - fTemp47);
			float fTemp49 = (fVec0[((IOTA - 14) & 63)] - fVec0[((IOTA - 46) & 63)]);
			float fTemp50 = (0.707106769f * fTemp49);
			float fTemp51 = ((fVec0[((IOTA - 54) & 63)] + (0.707106769f * fTemp48)) - (fVec0[((IOTA - 22) & 63)] + fTemp50));
			float fTemp52 = (fVec0[((IOTA - 10) & 63)] - fVec0[((IOTA - 42) & 63)]);
			float fTemp53 = (0.707106769f * fTemp52);
			float fTemp54 = (fVec0[((IOTA - 18) & 63)] + fTemp53);
			float fTemp55 = (0.707106769f * fTemp48);
			float fTemp56 = (0.707106769f * fTemp49);
			float fTemp57 = ((fTemp55 + (fVec0[((IOTA - 6) & 63)] + fTemp56)) - fVec0[((IOTA - 38) & 63)]);
			float fTemp58 = ((fTemp46 + (0.923879504f * fTemp51)) - (fTemp54 + (0.382683426f * fTemp57)));
			float fTemp59 = (fVec0[((IOTA - 28) & 63)] - fVec0[((IOTA - 60) & 63)]);
			float fTemp60 = (0.0f - fTemp59);
			float fTemp61 = (fVec0[((IOTA - 12) & 63)] - fVec0[((IOTA - 44) & 63)]);
			float fTemp62 = (0.707106769f * fTemp61);
			float fTemp63 = ((fVec0[((IOTA - 52) & 63)] + (0.707106769f * fTemp60)) - (fVec0[((IOTA - 20) & 63)] + fTemp62));
			float fTemp64 = (fVec0[((IOTA - 24) & 63)] - fVec0[((IOTA - 56) & 63)]);
			float fTemp65 = (0.0f - fTemp64);
			float fTemp66 = (0.707106769f * fTemp65);
			float fTemp67 = (fVec0[((IOTA - 8) & 63)] - fVec0[((IOTA - 40) & 63)]);
			float fTemp68 = (0.707106769f * fTemp67);
			float fTemp69 = (fTemp66 + (fTemp0 + fTemp68));
			float fTemp70 = (0.707106769f * fTemp60);
			float fTemp71 = (0.707106769f * fTemp61);
			float fTemp72 = ((fTemp70 + (fVec0[((IOTA - 4) & 63)] + fTemp71)) - fVec0[((IOTA - 36) & 63)]);
			float fTemp73 = ((0.382683426f * fTemp63) + (fTemp69 + (0.923879504f * fTemp72)));
			float fTemp74 = (0.707106769f * fTemp45);
			float fTemp75 = (0.707106769f * fTemp52);
			float fTemp76 = (fTemp74 + (fVec0[((IOTA - 2) & 63)] + fTemp75));
			float fTemp77 = (((0.382683426f * fTemp51) + (fTemp76 + (0.923879504f * fTemp57))) - fVec0[((IOTA - 34) & 63)]);
			float fTemp78 = (0.980785251f * fTemp77);
			float fTemp79 = (0.707106769f * fTemp8);
			float fTemp80 = (0.707106769f * fTemp32);
			float fTemp81 = (fTemp79 + (fVec0[((IOTA - 1) & 63)] + fTemp80));
			float fTemp82 = ((0.382683426f * fTemp14) + (fTemp81 + (0.923879504f * fTemp37)));
			float fTemp83 = (0.980785251f * fTemp42);
			float fTemp84 = (((0.195090324f * fTemp30) + (fTemp82 + fTemp83)) - fVec0[((IOTA - 33) & 63)]);
			float fTemp85 = (fVec0[((IOTA - 48) & 63)] + (0.707106769f * fTemp65));
			float fTemp86 = (fTemp85 + (0.923879504f * fTemp63));
			float fTemp87 = (0.980785251f * fTemp58);
			float fTemp88 = (0.707106769f * fTemp67);
			float fTemp89 = (fVec0[((IOTA - 16) & 63)] + fTemp88);
			float fTemp90 = (fTemp89 + (0.382683426f * fTemp72));
			output1[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.0980171412f * fTemp43) + (((0.195090324f * fTemp58) + (fTemp73 + fTemp78)) + (0.99518472f * fTemp84))) + (-1.0f - fVec0[((IOTA - 32) & 63)])))) + mydsp_faustpower2_f(std::fabs((((fTemp86 + fTemp87) + (0.99518472f * fTemp43)) - ((fTemp90 + (0.195090324f * fTemp77)) + (0.0980171412f * fTemp84)))))));
			float fTemp91 = (fVec0[((IOTA - 25) & 63)] + fVec0[((IOTA - 57) & 63)]);
			float fTemp92 = (fVec0[((IOTA - 13) & 63)] + fVec0[((IOTA - 45) & 63)]);
			float fTemp93 = (fTemp92 - (fVec0[((IOTA - 29) & 63)] + fVec0[((IOTA - 61) & 63)]));
			float fTemp94 = (0.0f - fTemp93);
			float fTemp95 = (fTemp91 + (0.707106769f * fTemp94));
			float fTemp96 = (fVec0[((IOTA - 27) & 63)] + fVec0[((IOTA - 59) & 63)]);
			float fTemp97 = (fVec0[((IOTA - 15) & 63)] + fVec0[((IOTA - 47) & 63)]);
			float fTemp98 = (fTemp97 - (fVec0[((IOTA - 31) & 63)] + fVec0[((IOTA - 63) & 63)]));
			float fTemp99 = (0.0f - fTemp98);
			float fTemp100 = (fVec0[((IOTA - 11) & 63)] + fVec0[((IOTA - 43) & 63)]);
			float fTemp101 = (fVec0[((IOTA - 7) & 63)] + fVec0[((IOTA - 39) & 63)]);
			float fTemp102 = (fTemp101 - (fVec0[((IOTA - 23) & 63)] + fVec0[((IOTA - 55) & 63)]));
			float fTemp103 = (0.707106769f * fTemp102);
			float fTemp104 = ((fTemp96 + (0.707106769f * fTemp99)) - (fTemp100 + fTemp103));
			float fTemp105 = (fVec0[((IOTA - 9) & 63)] + fVec0[((IOTA - 41) & 63)]);
			float fTemp106 = (fVec0[((IOTA - 5) & 63)] + fVec0[((IOTA - 37) & 63)]);
			float fTemp107 = (fTemp106 - (fVec0[((IOTA - 21) & 63)] + fVec0[((IOTA - 53) & 63)]));
			float fTemp108 = (0.707106769f * fTemp107);
			float fTemp109 = (fTemp105 + fTemp108);
			float fTemp110 = (0.707106769f * fTemp99);
			float fTemp111 = (fVec0[((IOTA - 3) & 63)] + fVec0[((IOTA - 35) & 63)]);
			float fTemp112 = (0.707106769f * fTemp102);
			float fTemp113 = (fVec0[((IOTA - 19) & 63)] + fVec0[((IOTA - 51) & 63)]);
			float fTemp114 = ((fTemp110 + (fTemp111 + fTemp112)) - fTemp113);
			float fTemp115 = ((fTemp95 + (0.923879504f * fTemp104)) - (fTemp109 + (0.382683426f * fTemp114)));
			float fTemp116 = (fVec0[((IOTA - 26) & 63)] + fVec0[((IOTA - 58) & 63)]);
			float fTemp117 = (fVec0[((IOTA - 14) & 63)] + fVec0[((IOTA - 46) & 63)]);
			float fTemp118 = (fTemp117 - (fVec0[((IOTA - 30) & 63)] + fVec0[((IOTA - 62) & 63)]));
			float fTemp119 = (0.0f - fTemp118);
			float fTemp120 = (fVec0[((IOTA - 10) & 63)] + fVec0[((IOTA - 42) & 63)]);
			float fTemp121 = (fVec0[((IOTA - 6) & 63)] + fVec0[((IOTA - 38) & 63)]);
			float fTemp122 = (fTemp121 - (fVec0[((IOTA - 22) & 63)] + fVec0[((IOTA - 54) & 63)]));
			float fTemp123 = (0.707106769f * fTemp122);
			float fTemp124 = ((fTemp116 + (0.707106769f * fTemp119)) - (fTemp120 + fTemp123));
			float fTemp125 = (fVec0[((IOTA - 12) & 63)] + fVec0[((IOTA - 44) & 63)]);
			float fTemp126 = (fTemp125 - (fVec0[((IOTA - 28) & 63)] + fVec0[((IOTA - 60) & 63)]));
			float fTemp127 = (0.0f - fTemp126);
			float fTemp128 = (0.707106769f * fTemp127);
			float fTemp129 = (fVec0[((IOTA - 4) & 63)] + fVec0[((IOTA - 36) & 63)]);
			float fTemp130 = (fTemp129 - (fVec0[((IOTA - 20) & 63)] + fVec0[((IOTA - 52) & 63)]));
			float fTemp131 = (0.707106769f * fTemp130);
			float fTemp132 = (fTemp128 + (fTemp2 + fTemp131));
			float fTemp133 = (0.707106769f * fTemp119);
			float fTemp134 = (fVec0[((IOTA - 2) & 63)] + fVec0[((IOTA - 34) & 63)]);
			float fTemp135 = (0.707106769f * fTemp122);
			float fTemp136 = (fVec0[((IOTA - 18) & 63)] + fVec0[((IOTA - 50) & 63)]);
			float fTemp137 = ((fTemp133 + (fTemp134 + fTemp135)) - fTemp136);
			float fTemp138 = (0.707106769f * fTemp94);
			float fTemp139 = (fVec0[((IOTA - 1) & 63)] + fVec0[((IOTA - 33) & 63)]);
			float fTemp140 = (0.707106769f * fTemp107);
			float fTemp141 = (fTemp138 + (fTemp139 + fTemp140));
			float fTemp142 = (fVec0[((IOTA - 17) & 63)] + fVec0[((IOTA - 49) & 63)]);
			float fTemp143 = (((0.382683426f * fTemp104) + (fTemp141 + (0.923879504f * fTemp114))) - fTemp142);
			float fTemp144 = (fVec0[((IOTA - 16) & 63)] + fVec0[((IOTA - 48) & 63)]);
			float fTemp145 = (fVec0[((IOTA - 24) & 63)] + fVec0[((IOTA - 56) & 63)]);
			float fTemp146 = (fTemp145 + (0.707106769f * fTemp127));
			float fTemp147 = (fVec0[((IOTA - 8) & 63)] + fVec0[((IOTA - 40) & 63)]);
			float fTemp148 = (0.707106769f * fTemp130);
			float fTemp149 = (fTemp147 + fTemp148);
			output2[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.195090324f * fTemp115) + (((0.382683426f * fTemp124) + (fTemp132 + (0.923879504f * fTemp137))) + (0.980785251f * fTemp143))) + (-1.0f - fTemp144)))) + mydsp_faustpower2_f(std::fabs((((fTemp146 + (0.923879504f * fTemp124)) + (0.980785251f * fTemp115)) - ((fTemp149 + (0.382683426f * fTemp137)) + (0.195090324f * fTemp143)))))));
			float fTemp150 = (fVec0[((IOTA - 21) & 63)] - ((0.707106769f * fTemp10) + (fVec0[((IOTA - 53) & 63)] + fTemp36)));
			float fTemp151 = (fVec0[((IOTA - 17) & 63)] + (0.382683426f * fTemp150));
			float fTemp152 = (fVec0[((IOTA - 23) & 63)] - ((0.707106769f * fTemp19) + (fVec0[((IOTA - 55) & 63)] + fTemp28)));
			float fTemp153 = ((0.707106769f * fTemp16) + (fVec0[((IOTA - 51) & 63)] + fTemp40));
			float fTemp154 = ((fVec0[((IOTA - 7) & 63)] + (0.707106769f * fTemp19)) - (fVec0[((IOTA - 39) & 63)] + fTemp22));
			float fTemp155 = ((fVec0[((IOTA - 19) & 63)] + (0.382683426f * fTemp152)) - (fTemp153 + (0.923879504f * fTemp154)));
			float fTemp156 = ((0.707106769f * fTemp7) + (fVec0[((IOTA - 49) & 63)] + fTemp80));
			float fTemp157 = ((fVec0[((IOTA - 5) & 63)] + (0.707106769f * fTemp10)) - (fVec0[((IOTA - 37) & 63)] + fTemp13));
			float fTemp158 = (fTemp156 + (0.923879504f * fTemp157));
			float fTemp159 = (fVec0[((IOTA - 3) & 63)] + (0.707106769f * fTemp16));
			float fTemp160 = (fVec0[((IOTA - 35) & 63)] + fTemp25);
			float fTemp161 = (((0.923879504f * fTemp152) + (fTemp159 + (0.382683426f * fTemp154))) - fTemp160);
			float fTemp162 = ((fTemp151 + (0.831469595f * fTemp155)) - (fTemp158 + (0.555570245f * fTemp161)));
			float fTemp163 = (fVec0[((IOTA - 22) & 63)] - ((0.707106769f * fTemp47) + (fVec0[((IOTA - 54) & 63)] + fTemp56)));
			float fTemp164 = ((0.707106769f * fTemp44) + (fVec0[((IOTA - 50) & 63)] + fTemp75));
			float fTemp165 = ((fVec0[((IOTA - 6) & 63)] + (0.707106769f * fTemp47)) - (fVec0[((IOTA - 38) & 63)] + fTemp50));
			float fTemp166 = ((fVec0[((IOTA - 18) & 63)] + (0.382683426f * fTemp163)) - (fTemp164 + (0.923879504f * fTemp165)));
			float fTemp167 = (fVec0[((IOTA - 20) & 63)] - ((0.707106769f * fTemp59) + (fVec0[((IOTA - 52) & 63)] + fTemp71)));
			float fTemp168 = (fTemp0 + (0.707106769f * fTemp64));
			float fTemp169 = ((fVec0[((IOTA - 4) & 63)] + (0.707106769f * fTemp59)) - (fVec0[((IOTA - 36) & 63)] + fTemp62));
			float fTemp170 = ((0.923879504f * fTemp167) + (fTemp168 + (0.382683426f * fTemp169)));
			float fTemp171 = (fVec0[((IOTA - 2) & 63)] + (0.707106769f * fTemp44));
			float fTemp172 = (fVec0[((IOTA - 34) & 63)] + fTemp53);
			float fTemp173 = (((0.923879504f * fTemp163) + (fTemp171 + (0.382683426f * fTemp165))) - fTemp172);
			float fTemp174 = (fVec0[((IOTA - 1) & 63)] + (0.707106769f * fTemp7));
			float fTemp175 = ((0.923879504f * fTemp150) + (fTemp174 + (0.382683426f * fTemp157)));
			float fTemp176 = (fVec0[((IOTA - 33) & 63)] + fTemp33);
			float fTemp177 = (((0.555570245f * fTemp155) + (fTemp175 + (0.831469595f * fTemp161))) - fTemp176);
			float fTemp178 = (fVec0[((IOTA - 32) & 63)] + fTemp88);
			float fTemp179 = (fVec0[((IOTA - 16) & 63)] + (0.382683426f * fTemp167));
			float fTemp180 = ((0.707106769f * fTemp64) + (fVec0[((IOTA - 48) & 63)] + fTemp68));
			float fTemp181 = (fTemp180 + (0.923879504f * fTemp169));
			output3[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.290284663f * fTemp162) + (((0.555570245f * fTemp166) + (fTemp170 + (0.831469595f * fTemp173))) + (0.956940353f * fTemp177))) + (-1.0f - fTemp178)))) + mydsp_faustpower2_f(std::fabs((((fTemp179 + (0.831469595f * fTemp166)) + (0.956940353f * fTemp162)) - ((fTemp181 + (0.555570245f * fTemp173)) + (0.290284663f * fTemp177)))))));
			float fTemp182 = (fVec0[((IOTA - 61) & 63)] + (fTemp92 + fVec0[((IOTA - 29) & 63)]));
			float fTemp183 = (fVec0[((IOTA - 55) & 63)] + (fTemp101 + fVec0[((IOTA - 23) & 63)]));
			float fTemp184 = (fTemp183 - (fVec0[((IOTA - 63) & 63)] + (fTemp97 + fVec0[((IOTA - 31) & 63)])));
			float fTemp185 = (0.0f - fTemp184);
			float fTemp186 = (fVec0[((IOTA - 53) & 63)] + (fTemp106 + fVec0[((IOTA - 21) & 63)]));
			float fTemp187 = (fVec0[((IOTA - 51) & 63)] + (fTemp111 + fVec0[((IOTA - 19) & 63)]));
			float fTemp188 = (fTemp187 - (fVec0[((IOTA - 59) & 63)] + (fTemp100 + fVec0[((IOTA - 27) & 63)])));
			float fTemp189 = (0.707106769f * fTemp188);
			float fTemp190 = ((fTemp182 + (0.707106769f * fTemp185)) - (fTemp186 + fTemp189));
			float fTemp191 = (fVec0[((IOTA - 54) & 63)] + (fTemp121 + fVec0[((IOTA - 22) & 63)]));
			float fTemp192 = (fTemp191 - (fVec0[((IOTA - 62) & 63)] + (fTemp117 + fVec0[((IOTA - 30) & 63)])));
			float fTemp193 = (0.0f - fTemp192);
			float fTemp194 = (0.707106769f * fTemp193);
			float fTemp195 = (fVec0[((IOTA - 50) & 63)] + (fTemp134 + fVec0[((IOTA - 18) & 63)]));
			float fTemp196 = (fTemp195 - (fVec0[((IOTA - 58) & 63)] + (fTemp120 + fVec0[((IOTA - 26) & 63)])));
			float fTemp197 = (0.707106769f * fTemp196);
			float fTemp198 = (0.707106769f * fTemp185);
			float fTemp199 = (fVec0[((IOTA - 49) & 63)] + (fTemp139 + fVec0[((IOTA - 17) & 63)]));
			float fTemp200 = (0.707106769f * fTemp188);
			float fTemp201 = (fVec0[((IOTA - 57) & 63)] + (fTemp105 + fVec0[((IOTA - 25) & 63)]));
			float fTemp202 = ((fTemp198 + (fTemp199 + fTemp200)) - fTemp201);
			float fTemp203 = (fVec0[((IOTA - 56) & 63)] + (fTemp147 + fVec0[((IOTA - 24) & 63)]));
			float fTemp204 = (fVec0[((IOTA - 60) & 63)] + (fTemp125 + fVec0[((IOTA - 28) & 63)]));
			float fTemp205 = (fVec0[((IOTA - 52) & 63)] + (fTemp129 + fVec0[((IOTA - 20) & 63)]));
			float fTemp206 = (0.707106769f * fTemp196);
			output4[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.382683426f * fTemp190) + ((fTemp194 + (fTemp3 + fTemp197)) + (0.923879504f * fTemp202))) + (-1.0f - fTemp203)))) + mydsp_faustpower2_f(std::fabs((((fTemp204 + (0.707106769f * fTemp193)) + (0.923879504f * fTemp190)) - ((fTemp205 + fTemp206) + (0.382683426f * fTemp202)))))));
			float fTemp207 = (fVec0[((IOTA - 49) & 63)] + fTemp33);
			float fTemp208 = (fVec0[((IOTA - 51) & 63)] + fTemp25);
			float fTemp209 = ((fVec0[((IOTA - 55) & 63)] + fTemp22) - (fVec0[((IOTA - 23) & 63)] + (0.707106769f * fTemp20)));
			float fTemp210 = (fVec0[((IOTA - 19) & 63)] + (0.707106769f * fTemp17));
			float fTemp211 = (0.707106769f * fTemp21);
			float fTemp212 = (fVec0[((IOTA - 7) & 63)] - (fTemp27 + (fVec0[((IOTA - 39) & 63)] + fTemp211)));
			float fTemp213 = (fTemp208 - ((0.382683426f * fTemp209) + (fTemp210 + (0.923879504f * fTemp212))));
			float fTemp214 = ((fVec0[((IOTA - 53) & 63)] + fTemp13) - (fVec0[((IOTA - 21) & 63)] + (0.707106769f * fTemp11)));
			float fTemp215 = (fVec0[((IOTA - 17) & 63)] + (0.707106769f * fTemp8));
			float fTemp216 = (0.707106769f * fTemp12);
			float fTemp217 = (fVec0[((IOTA - 5) & 63)] - (fTemp35 + (fVec0[((IOTA - 37) & 63)] + fTemp216)));
			float fTemp218 = ((0.382683426f * fTemp214) + (fTemp215 + (0.923879504f * fTemp217)));
			float fTemp219 = (0.707106769f * fTemp24);
			float fTemp220 = (fTemp39 + (fVec0[((IOTA - 35) & 63)] + fTemp219));
			float fTemp221 = ((fVec0[((IOTA - 3) & 63)] + (0.923879504f * fTemp209)) - (fTemp220 + (0.382683426f * fTemp212)));
			float fTemp222 = (0.831469595f * fTemp221);
			float fTemp223 = ((fTemp207 + (0.555570245f * fTemp213)) - (fTemp218 + fTemp222));
			float fTemp224 = (fVec0[((IOTA - 50) & 63)] + fTemp53);
			float fTemp225 = ((fVec0[((IOTA - 54) & 63)] + fTemp50) - (fVec0[((IOTA - 22) & 63)] + (0.707106769f * fTemp48)));
			float fTemp226 = (fVec0[((IOTA - 18) & 63)] + (0.707106769f * fTemp45));
			float fTemp227 = (0.707106769f * fTemp49);
			float fTemp228 = (fVec0[((IOTA - 6) & 63)] - (fTemp55 + (fVec0[((IOTA - 38) & 63)] + fTemp227)));
			float fTemp229 = (fTemp224 - ((0.382683426f * fTemp225) + (fTemp226 + (0.923879504f * fTemp228))));
			float fTemp230 = (0.831469595f * fTemp229);
			float fTemp231 = ((fVec0[((IOTA - 52) & 63)] + fTemp62) - (fVec0[((IOTA - 20) & 63)] + (0.707106769f * fTemp60)));
			float fTemp232 = (fTemp0 + (0.923879504f * fTemp231));
			float fTemp233 = (0.707106769f * fTemp52);
			float fTemp234 = (fTemp74 + (fVec0[((IOTA - 34) & 63)] + fTemp233));
			float fTemp235 = ((fVec0[((IOTA - 2) & 63)] + (0.923879504f * fTemp225)) - (fTemp234 + (0.382683426f * fTemp228)));
			float fTemp236 = (0.831469595f * fTemp213);
			float fTemp237 = (fVec0[((IOTA - 1) & 63)] + (0.923879504f * fTemp214));
			float fTemp238 = (0.707106769f * fTemp32);
			float fTemp239 = (fTemp79 + (fVec0[((IOTA - 33) & 63)] + fTemp238));
			float fTemp240 = (fTemp239 + (0.382683426f * fTemp217));
			float fTemp241 = ((fTemp236 + (fTemp237 + (0.555570245f * fTemp221))) - fTemp240);
			float fTemp242 = (0.707106769f * fTemp67);
			float fTemp243 = (fTemp66 + (fVec0[((IOTA - 32) & 63)] + fTemp242));
			float fTemp244 = (0.707106769f * fTemp61);
			float fTemp245 = (fVec0[((IOTA - 4) & 63)] - (fTemp70 + (fVec0[((IOTA - 36) & 63)] + fTemp244)));
			float fTemp246 = (fTemp243 + (0.382683426f * fTemp245));
			float fTemp247 = (fVec0[((IOTA - 48) & 63)] + fTemp88);
			float fTemp248 = (fVec0[((IOTA - 16) & 63)] + (0.707106769f * fTemp65));
			float fTemp249 = ((0.382683426f * fTemp231) + (fTemp248 + (0.923879504f * fTemp245)));
			float fTemp250 = (0.831469595f * fTemp235);
			output5[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.471396744f * fTemp223) + ((fTemp230 + (fTemp232 + (0.555570245f * fTemp235))) + (0.881921291f * fTemp241))) + (-1.0f - fTemp246)))) + mydsp_faustpower2_f(std::fabs((((fTemp247 + (0.555570245f * fTemp229)) + (0.881921291f * fTemp223)) - ((fTemp249 + fTemp250) + (0.471396744f * fTemp241)))))));
			float fTemp251 = (fTemp100 - ((0.707106769f * fTemp98) + (fTemp96 + fTemp112)));
			float fTemp252 = ((0.707106769f * fTemp93) + (fTemp91 + fTemp140));
			float fTemp253 = ((fTemp111 + (0.707106769f * fTemp98)) - (fTemp113 + fTemp103));
			float fTemp254 = ((fTemp105 + (0.382683426f * fTemp251)) - (fTemp252 + (0.923879504f * fTemp253)));
			float fTemp255 = (fTemp120 - ((0.707106769f * fTemp118) + (fTemp116 + fTemp135)));
			float fTemp256 = (fTemp2 + (0.707106769f * fTemp126));
			float fTemp257 = ((fTemp134 + (0.707106769f * fTemp118)) - (fTemp136 + fTemp123));
			float fTemp258 = (fTemp139 + (0.707106769f * fTemp93));
			float fTemp259 = (fTemp142 + fTemp108);
			float fTemp260 = (((0.923879504f * fTemp251) + (fTemp258 + (0.382683426f * fTemp253))) - fTemp259);
			float fTemp261 = (fTemp144 + fTemp148);
			float fTemp262 = ((0.707106769f * fTemp126) + (fTemp145 + fTemp131));
			output6[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.555570245f * fTemp254) + (((0.923879504f * fTemp255) + (fTemp256 + (0.382683426f * fTemp257))) + (0.831469595f * fTemp260))) + (-1.0f - fTemp261)))) + mydsp_faustpower2_f(std::fabs((((fTemp147 + (0.382683426f * fTemp255)) + (0.831469595f * fTemp254)) - ((fTemp262 + (0.923879504f * fTemp257)) + (0.555570245f * fTemp260)))))));
			float fTemp263 = ((0.707106769f * fTemp7) + (fVec0[((IOTA - 17) & 63)] + fTemp238));
			float fTemp264 = ((0.707106769f * fTemp16) + (fVec0[((IOTA - 19) & 63)] + fTemp219));
			float fTemp265 = (((0.707106769f * fTemp19) + (fVec0[((IOTA - 23) & 63)] + fTemp211)) - fVec0[((IOTA - 55) & 63)]);
			float fTemp266 = ((fVec0[((IOTA - 7) & 63)] + (0.707106769f * fTemp21)) - (fVec0[((IOTA - 39) & 63)] + (0.707106769f * fTemp19)));
			float fTemp267 = (fTemp264 - ((0.923879504f * fTemp265) + (fVec0[((IOTA - 51) & 63)] + (0.382683426f * fTemp266))));
			float fTemp268 = (((0.707106769f * fTemp10) + (fVec0[((IOTA - 21) & 63)] + fTemp216)) - fVec0[((IOTA - 53) & 63)]);
			float fTemp269 = ((fVec0[((IOTA - 5) & 63)] + (0.707106769f * fTemp12)) - (fVec0[((IOTA - 37) & 63)] + (0.707106769f * fTemp10)));
			float fTemp270 = ((0.923879504f * fTemp268) + (fVec0[((IOTA - 49) & 63)] + (0.382683426f * fTemp269)));
			float fTemp271 = (fVec0[((IOTA - 3) & 63)] + (0.707106769f * fTemp24));
			float fTemp272 = (fVec0[((IOTA - 35) & 63)] + (0.707106769f * fTemp16));
			float fTemp273 = ((fTemp271 + (0.382683426f * fTemp265)) - (fTemp272 + (0.923879504f * fTemp266)));
			float fTemp274 = ((fTemp263 + (0.195090324f * fTemp267)) - (fTemp270 + (0.980785251f * fTemp273)));
			float fTemp275 = ((0.707106769f * fTemp44) + (fVec0[((IOTA - 18) & 63)] + fTemp233));
			float fTemp276 = (((0.707106769f * fTemp47) + (fVec0[((IOTA - 22) & 63)] + fTemp227)) - fVec0[((IOTA - 54) & 63)]);
			float fTemp277 = ((fVec0[((IOTA - 6) & 63)] + (0.707106769f * fTemp49)) - (fVec0[((IOTA - 38) & 63)] + (0.707106769f * fTemp47)));
			float fTemp278 = (fTemp275 - ((0.923879504f * fTemp276) + (fVec0[((IOTA - 50) & 63)] + (0.382683426f * fTemp277))));
			float fTemp279 = (fTemp0 + (0.707106769f * fTemp67));
			float fTemp280 = (((0.707106769f * fTemp59) + (fVec0[((IOTA - 20) & 63)] + fTemp244)) - fVec0[((IOTA - 52) & 63)]);
			float fTemp281 = (fTemp279 + (0.382683426f * fTemp280));
			float fTemp282 = (fVec0[((IOTA - 2) & 63)] + (0.707106769f * fTemp52));
			float fTemp283 = (fVec0[((IOTA - 34) & 63)] + (0.707106769f * fTemp44));
			float fTemp284 = ((fTemp282 + (0.382683426f * fTemp276)) - (fTemp283 + (0.923879504f * fTemp277)));
			float fTemp285 = (fVec0[((IOTA - 1) & 63)] + (0.707106769f * fTemp32));
			float fTemp286 = (fTemp285 + (0.382683426f * fTemp268));
			float fTemp287 = (fVec0[((IOTA - 33) & 63)] + (0.707106769f * fTemp7));
			float fTemp288 = (fTemp287 + (0.923879504f * fTemp269));
			float fTemp289 = (((0.980785251f * fTemp267) + (fTemp286 + (0.195090324f * fTemp273))) - fTemp288);
			float fTemp290 = (fVec0[((IOTA - 32) & 63)] + (0.707106769f * fTemp64));
			float fTemp291 = ((fVec0[((IOTA - 4) & 63)] + (0.707106769f * fTemp61)) - (fVec0[((IOTA - 36) & 63)] + (0.707106769f * fTemp59)));
			float fTemp292 = (fTemp290 + (0.923879504f * fTemp291));
			float fTemp293 = ((0.707106769f * fTemp64) + (fVec0[((IOTA - 16) & 63)] + fTemp242));
			float fTemp294 = ((0.923879504f * fTemp280) + (fVec0[((IOTA - 48) & 63)] + (0.382683426f * fTemp291)));
			output7[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.634393275f * fTemp274) + (((0.980785251f * fTemp278) + (fTemp281 + (0.195090324f * fTemp284))) + (0.773010433f * fTemp289))) + (-1.0f - fTemp292)))) + mydsp_faustpower2_f(std::fabs((((fTemp293 + (0.195090324f * fTemp278)) + (0.773010433f * fTemp274)) - ((fTemp294 + (0.980785251f * fTemp284)) + (0.634393275f * fTemp289)))))));
			float fTemp295 = (fVec0[((IOTA - 59) & 63)] + (fVec0[((IOTA - 27) & 63)] + (fVec0[((IOTA - 43) & 63)] + (fTemp187 + fVec0[((IOTA - 11) & 63)]))));
			float fTemp296 = (fTemp295 - (fVec0[((IOTA - 63) & 63)] + (fVec0[((IOTA - 31) & 63)] + (fVec0[((IOTA - 47) & 63)] + (fTemp183 + fVec0[((IOTA - 15) & 63)])))));
			float fTemp297 = (0.0f - fTemp296);
			float fTemp298 = (fVec0[((IOTA - 57) & 63)] + (fVec0[((IOTA - 25) & 63)] + (fVec0[((IOTA - 41) & 63)] + (fTemp199 + fVec0[((IOTA - 9) & 63)]))));
			float fTemp299 = (fTemp298 - (fVec0[((IOTA - 61) & 63)] + (fVec0[((IOTA - 29) & 63)] + (fVec0[((IOTA - 45) & 63)] + (fTemp186 + fVec0[((IOTA - 13) & 63)])))));
			float fTemp300 = (0.707106769f * fTemp299);
			float fTemp301 = (fVec0[((IOTA - 60) & 63)] + (fVec0[((IOTA - 28) & 63)] + (fVec0[((IOTA - 44) & 63)] + (fTemp205 + fVec0[((IOTA - 12) & 63)]))));
			float fTemp302 = (fVec0[((IOTA - 62) & 63)] + (fVec0[((IOTA - 30) & 63)] + (fVec0[((IOTA - 46) & 63)] + (fTemp191 + fVec0[((IOTA - 14) & 63)]))));
			float fTemp303 = (fVec0[((IOTA - 58) & 63)] + (fVec0[((IOTA - 26) & 63)] + (fVec0[((IOTA - 42) & 63)] + (fTemp195 + fVec0[((IOTA - 10) & 63)]))));
			float fTemp304 = (0.707106769f * fTemp299);
			output8[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.707106769f * fTemp297) + (fTemp4 + fTemp300)) + (-1.0f - fTemp301)))) + mydsp_faustpower2_f(std::fabs(((fTemp302 + (0.707106769f * fTemp297)) - (fTemp303 + fTemp304))))));
			float fTemp305 = (fTemp9 + (0.382683426f * fTemp37));
			float fTemp306 = ((fTemp18 + (0.382683426f * fTemp29)) - (fTemp26 + (0.923879504f * fTemp23)));
			float fTemp307 = (fTemp34 + (0.923879504f * fTemp14));
			float fTemp308 = (fTemp41 - ((0.382683426f * fTemp23) + (fVec0[((IOTA - 35) & 63)] + (0.923879504f * fTemp29))));
			float fTemp309 = (0.980785251f * fTemp308);
			float fTemp310 = (fTemp305 - ((0.195090324f * fTemp306) + (fTemp307 + fTemp309)));
			float fTemp311 = ((fTemp46 + (0.382683426f * fTemp57)) - (fTemp54 + (0.923879504f * fTemp51)));
			float fTemp312 = (0.980785251f * fTemp311);
			float fTemp313 = (0.980785251f * fTemp306);
			float fTemp314 = ((0.382683426f * fTemp14) + (fVec0[((IOTA - 33) & 63)] + (0.923879504f * fTemp37)));
			float fTemp315 = ((fTemp81 + fTemp313) - (fTemp314 + (0.195090324f * fTemp308)));
			float fTemp316 = ((0.382683426f * fTemp63) + (fVec0[((IOTA - 32) & 63)] + (0.923879504f * fTemp72)));
			float fTemp317 = (fTemp76 - ((0.382683426f * fTemp51) + (fVec0[((IOTA - 34) & 63)] + (0.923879504f * fTemp57))));
			float fTemp318 = (fTemp85 + (0.382683426f * fTemp72));
			float fTemp319 = (fTemp89 + (0.923879504f * fTemp63));
			float fTemp320 = (0.980785251f * fTemp317);
			output9[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.773010433f * fTemp310) + ((fTemp69 + fTemp312) + (0.634393275f * fTemp315))) + (-1.0f - (fTemp316 + (0.195090324f * fTemp317)))))) + mydsp_faustpower2_f(std::fabs(((fTemp318 + (0.634393275f * fTemp310)) - (((0.195090324f * fTemp311) + (fTemp319 + fTemp320)) + (0.773010433f * fTemp315)))))));
			float fTemp321 = (fTemp91 + fTemp108);
			float fTemp322 = ((fTemp96 + fTemp103) - (fTemp100 + (0.707106769f * fTemp99)));
			float fTemp323 = (fTemp105 + (0.707106769f * fTemp94));
			float fTemp324 = (0.707106769f * fTemp102);
			float fTemp325 = (fTemp111 - (fTemp110 + (fTemp113 + fTemp324)));
			float fTemp326 = (fTemp321 - ((0.382683426f * fTemp322) + (fTemp323 + (0.923879504f * fTemp325))));
			float fTemp327 = ((fTemp116 + fTemp123) - (fTemp120 + (0.707106769f * fTemp119)));
			float fTemp328 = (0.707106769f * fTemp107);
			float fTemp329 = (fTemp138 + (fTemp142 + fTemp328));
			float fTemp330 = ((fTemp139 + (0.923879504f * fTemp322)) - (fTemp329 + (0.382683426f * fTemp325)));
			float fTemp331 = (0.707106769f * fTemp130);
			float fTemp332 = (fTemp128 + (fTemp144 + fTemp331));
			float fTemp333 = (0.707106769f * fTemp122);
			float fTemp334 = (fTemp134 - (fTemp133 + (fTemp136 + fTemp333)));
			float fTemp335 = (fTemp145 + fTemp148);
			float fTemp336 = (fTemp147 + (0.707106769f * fTemp127));
			output10[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.831469595f * fTemp326) + ((fTemp2 + (0.923879504f * fTemp327)) + (0.555570245f * fTemp330))) + (-1.0f - (fTemp332 + (0.382683426f * fTemp334)))))) + mydsp_faustpower2_f(std::fabs(((fTemp335 + (0.555570245f * fTemp326)) - (((0.382683426f * fTemp327) + (fTemp336 + (0.923879504f * fTemp334))) + (0.831469595f * fTemp330)))))));
			float fTemp337 = (fVec0[((IOTA - 17) & 63)] + (0.923879504f * fTemp157));
			float fTemp338 = ((fVec0[((IOTA - 19) & 63)] + (0.923879504f * fTemp154)) - (fTemp153 + (0.382683426f * fTemp152)));
			float fTemp339 = (fTemp156 + (0.382683426f * fTemp150));
			float fTemp340 = (fTemp159 - ((0.923879504f * fTemp152) + (fTemp160 + (0.382683426f * fTemp154))));
			float fTemp341 = (0.831469595f * fTemp340);
			float fTemp342 = (fTemp337 - ((0.555570245f * fTemp338) + (fTemp339 + fTemp341)));
			float fTemp343 = ((fVec0[((IOTA - 18) & 63)] + (0.923879504f * fTemp165)) - (fTemp164 + (0.382683426f * fTemp163)));
			float fTemp344 = (0.831469595f * fTemp343);
			float fTemp345 = (0.831469595f * fTemp338);
			float fTemp346 = ((0.923879504f * fTemp150) + (fTemp176 + (0.382683426f * fTemp157)));
			float fTemp347 = ((fTemp174 + fTemp345) - (fTemp346 + (0.555570245f * fTemp340)));
			float fTemp348 = ((0.923879504f * fTemp167) + (fTemp178 + (0.382683426f * fTemp169)));
			float fTemp349 = (fTemp171 - ((0.923879504f * fTemp163) + (fTemp172 + (0.382683426f * fTemp165))));
			float fTemp350 = (fVec0[((IOTA - 16) & 63)] + (0.923879504f * fTemp169));
			float fTemp351 = (fTemp180 + (0.382683426f * fTemp167));
			float fTemp352 = (0.831469595f * fTemp349);
			output11[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.881921291f * fTemp342) + ((fTemp168 + fTemp344) + (0.471396744f * fTemp347))) + (-1.0f - (fTemp348 + (0.555570245f * fTemp349)))))) + mydsp_faustpower2_f(std::fabs(((fTemp350 + (0.471396744f * fTemp342)) - (((0.555570245f * fTemp343) + (fTemp351 + fTemp352)) + (0.881921291f * fTemp347)))))));
			float fTemp353 = (fTemp186 - ((0.707106769f * fTemp184) + (fTemp182 + fTemp200)));
			float fTemp354 = ((fTemp199 + (0.707106769f * fTemp184)) - (fTemp201 + fTemp189));
			output12[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.923879504f * fTemp353) + ((fTemp3 + (0.707106769f * fTemp192)) + (0.382683426f * fTemp354))) + (-1.0f - (fTemp203 + fTemp206))))) + mydsp_faustpower2_f(std::fabs(((fTemp205 + (0.382683426f * fTemp353)) - (((0.707106769f * fTemp192) + (fTemp204 + fTemp197)) + (0.923879504f * fTemp354)))))));
			float fTemp355 = ((0.382683426f * fTemp214) + (fTemp207 + (0.923879504f * fTemp217)));
			float fTemp356 = (((0.382683426f * fTemp209) + (fTemp208 + (0.923879504f * fTemp212))) - fTemp210);
			float fTemp357 = ((fVec0[((IOTA - 3) & 63)] + (0.382683426f * fTemp212)) - (fTemp220 + (0.923879504f * fTemp209)));
			float fTemp358 = (0.555570245f * fTemp357);
			float fTemp359 = (fTemp355 - ((0.831469595f * fTemp356) + (fTemp215 + fTemp358)));
			float fTemp360 = (fTemp0 + (0.382683426f * fTemp245));
			float fTemp361 = (((0.382683426f * fTemp225) + (fTemp224 + (0.923879504f * fTemp228))) - fTemp226);
			float fTemp362 = (0.555570245f * fTemp361);
			float fTemp363 = (fVec0[((IOTA - 1) & 63)] + (0.382683426f * fTemp217));
			float fTemp364 = (0.555570245f * fTemp356);
			float fTemp365 = (fTemp239 + (0.923879504f * fTemp214));
			float fTemp366 = ((fTemp363 + fTemp364) - (fTemp365 + (0.831469595f * fTemp357)));
			float fTemp367 = (fTemp243 + (0.923879504f * fTemp231));
			float fTemp368 = ((fVec0[((IOTA - 2) & 63)] + (0.382683426f * fTemp228)) - (fTemp234 + (0.923879504f * fTemp225)));
			float fTemp369 = ((0.382683426f * fTemp231) + (fTemp247 + (0.923879504f * fTemp245)));
			float fTemp370 = (0.555570245f * fTemp368);
			output13[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.956940353f * fTemp359) + ((fTemp360 + fTemp362) + (0.290284663f * fTemp366))) + (-1.0f - (fTemp367 + (0.831469595f * fTemp368)))))) + mydsp_faustpower2_f(std::fabs(((fTemp369 + (0.290284663f * fTemp359)) - (((0.831469595f * fTemp361) + (fTemp248 + fTemp370)) + (0.956940353f * fTemp366)))))));
			float fTemp371 = ((0.707106769f * fTemp93) + (fTemp105 + fTemp328));
			float fTemp372 = (((0.707106769f * fTemp98) + (fTemp100 + fTemp324)) - fTemp96);
			float fTemp373 = ((fTemp111 + (0.707106769f * fTemp102)) - (fTemp113 + (0.707106769f * fTemp98)));
			float fTemp374 = (fTemp371 - ((0.923879504f * fTemp372) + (fTemp91 + (0.382683426f * fTemp373))));
			float fTemp375 = (fTemp2 + (0.707106769f * fTemp130));
			float fTemp376 = (((0.707106769f * fTemp118) + (fTemp120 + fTemp333)) - fTemp116);
			float fTemp377 = (fTemp139 + (0.707106769f * fTemp107));
			float fTemp378 = (fTemp142 + (0.707106769f * fTemp93));
			float fTemp379 = ((fTemp377 + (0.382683426f * fTemp372)) - (fTemp378 + (0.923879504f * fTemp373)));
			float fTemp380 = (fTemp144 + (0.707106769f * fTemp126));
			float fTemp381 = ((fTemp134 + (0.707106769f * fTemp122)) - (fTemp136 + (0.707106769f * fTemp118)));
			float fTemp382 = ((0.707106769f * fTemp126) + (fTemp147 + fTemp331));
			output14[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.980785251f * fTemp374) + ((fTemp375 + (0.382683426f * fTemp376)) + (0.195090324f * fTemp379))) + (-1.0f - (fTemp380 + (0.923879504f * fTemp381)))))) + mydsp_faustpower2_f(std::fabs(((fTemp382 + (0.195090324f * fTemp374)) - (((0.923879504f * fTemp376) + (fTemp145 + (0.382683426f * fTemp381))) + (0.980785251f * fTemp379)))))));
			float fTemp383 = ((0.923879504f * fTemp268) + (fTemp263 + (0.382683426f * fTemp269)));
			float fTemp384 = (((0.923879504f * fTemp265) + (fTemp264 + (0.382683426f * fTemp266))) - fVec0[((IOTA - 51) & 63)]);
			float fTemp385 = ((fTemp271 + (0.923879504f * fTemp266)) - (fTemp272 + (0.382683426f * fTemp265)));
			float fTemp386 = (fTemp383 - ((0.980785251f * fTemp384) + (fVec0[((IOTA - 49) & 63)] + (0.195090324f * fTemp385))));
			float fTemp387 = (fTemp279 + (0.923879504f * fTemp291));
			float fTemp388 = (((0.923879504f * fTemp276) + (fTemp275 + (0.382683426f * fTemp277))) - fVec0[((IOTA - 50) & 63)]);
			float fTemp389 = (fTemp285 + (0.923879504f * fTemp269));
			float fTemp390 = (fTemp287 + (0.382683426f * fTemp268));
			float fTemp391 = ((fTemp389 + (0.195090324f * fTemp384)) - (fTemp390 + (0.980785251f * fTemp385)));
			float fTemp392 = (fTemp290 + (0.382683426f * fTemp280));
			float fTemp393 = ((fTemp282 + (0.923879504f * fTemp277)) - (fTemp283 + (0.382683426f * fTemp276)));
			float fTemp394 = ((0.923879504f * fTemp280) + (fTemp293 + (0.382683426f * fTemp291)));
			output15[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.99518472f * fTemp386) + ((fTemp387 + (0.195090324f * fTemp388)) + (0.0980171412f * fTemp391))) + (-1.0f - (fTemp392 + (0.980785251f * fTemp393)))))) + mydsp_faustpower2_f(std::fabs(((fTemp394 + (0.0980171412f * fTemp386)) - (((0.980785251f * fTemp388) + (fVec0[((IOTA - 48) & 63)] + (0.195090324f * fTemp393))) + (0.99518472f * fTemp391)))))));
			float fTemp395 = (fVec0[((IOTA - 61) & 63)] + (fVec0[((IOTA - 29) & 63)] + (fVec0[((IOTA - 45) & 63)] + (fVec0[((IOTA - 13) & 63)] + (fVec0[((IOTA - 53) & 63)] + (fVec0[((IOTA - 21) & 63)] + (fVec0[((IOTA - 37) & 63)] + (fTemp298 + fVec0[((IOTA - 5) & 63)]))))))));
			output16[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((fTemp5 + (-1.0f - (fVec0[((IOTA - 62) & 63)] + (fVec0[((IOTA - 30) & 63)] + (fVec0[((IOTA - 46) & 63)] + (fVec0[((IOTA - 14) & 63)] + (fVec0[((IOTA - 54) & 63)] + (fVec0[((IOTA - 22) & 63)] + (fVec0[((IOTA - 38) & 63)] + (fTemp303 + fVec0[((IOTA - 6) & 63)])))))))))))) + mydsp_faustpower2_f(std::fabs((0.0f - (fTemp395 - (fVec0[((IOTA - 63) & 63)] + (fVec0[((IOTA - 31) & 63)] + (fVec0[((IOTA - 47) & 63)] + (fVec0[((IOTA - 15) & 63)] + (fVec0[((IOTA - 55) & 63)] + (fVec0[((IOTA - 23) & 63)] + (fVec0[((IOTA - 39) & 63)] + (fTemp295 + fVec0[((IOTA - 7) & 63)]))))))))))))));
			float fTemp396 = ((fTemp15 + (0.195090324f * fTemp42)) - (fTemp38 + fTemp31));
			float fTemp397 = (fTemp82 - ((0.195090324f * fTemp30) + (fVec0[((IOTA - 33) & 63)] + fTemp83)));
			output17[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp73 + (0.99518472f * fTemp396)) + (-1.0f - (((0.195090324f * fTemp58) + (fVec0[((IOTA - 32) & 63)] + fTemp78)) + (0.0980171412f * fTemp397)))))) + mydsp_faustpower2_f(std::fabs(((fTemp86 + (0.195090324f * fTemp77)) - ((0.0980171412f * fTemp396) + ((fTemp90 + fTemp87) + (0.99518472f * fTemp397))))))));
			float fTemp398 = ((fTemp95 + (0.382683426f * fTemp114)) - (fTemp109 + (0.923879504f * fTemp104)));
			float fTemp399 = (fTemp141 - ((0.382683426f * fTemp104) + (fTemp142 + (0.923879504f * fTemp114))));
			output18[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp132 + (0.980785251f * fTemp398)) + (-1.0f - (((0.382683426f * fTemp124) + (fTemp144 + (0.923879504f * fTemp137))) + (0.195090324f * fTemp399)))))) + mydsp_faustpower2_f(std::fabs(((fTemp146 + (0.382683426f * fTemp137)) - ((0.195090324f * fTemp398) + ((fTemp149 + (0.923879504f * fTemp124)) + (0.980785251f * fTemp399))))))));
			float fTemp400 = ((fTemp151 + (0.555570245f * fTemp161)) - (fTemp158 + (0.831469595f * fTemp155)));
			float fTemp401 = (fTemp175 - ((0.555570245f * fTemp155) + (fTemp176 + (0.831469595f * fTemp161))));
			output19[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp170 + (0.956940353f * fTemp400)) + (-1.0f - (((0.555570245f * fTemp166) + (fTemp178 + (0.831469595f * fTemp173))) + (0.290284663f * fTemp401)))))) + mydsp_faustpower2_f(std::fabs(((fTemp179 + (0.555570245f * fTemp173)) - ((0.290284663f * fTemp400) + ((fTemp181 + (0.831469595f * fTemp166)) + (0.956940353f * fTemp401))))))));
			float fTemp402 = ((fTemp182 + fTemp189) - (fTemp186 + (0.707106769f * fTemp185)));
			float fTemp403 = (0.707106769f * fTemp196);
			float fTemp404 = (0.707106769f * fTemp188);
			float fTemp405 = (fTemp199 - (fTemp198 + (fTemp201 + fTemp404)));
			output20[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp3 + (0.923879504f * fTemp402)) + (-1.0f - ((fTemp194 + (fTemp203 + fTemp403)) + (0.382683426f * fTemp405)))))) + mydsp_faustpower2_f(std::fabs(((fTemp204 + fTemp206) - ((0.382683426f * fTemp402) + ((fTemp205 + (0.707106769f * fTemp193)) + (0.923879504f * fTemp405))))))));
			float fTemp406 = ((fTemp207 + fTemp222) - (fTemp218 + (0.555570245f * fTemp213)));
			float fTemp407 = (fTemp237 - (fTemp236 + (fTemp240 + (0.555570245f * fTemp221))));
			output21[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp232 + (0.881921291f * fTemp406)) + (-1.0f - ((fTemp230 + (fTemp246 + (0.555570245f * fTemp235))) + (0.471396744f * fTemp407)))))) + mydsp_faustpower2_f(std::fabs(((fTemp247 + fTemp250) - ((0.471396744f * fTemp406) + ((fTemp249 + (0.555570245f * fTemp229)) + (0.881921291f * fTemp407))))))));
			float fTemp408 = ((fTemp105 + (0.923879504f * fTemp253)) - (fTemp252 + (0.382683426f * fTemp251)));
			float fTemp409 = (fTemp258 - ((0.923879504f * fTemp251) + (fTemp259 + (0.382683426f * fTemp253))));
			output22[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp256 + (0.831469595f * fTemp408)) + (-1.0f - (((0.923879504f * fTemp255) + (fTemp261 + (0.382683426f * fTemp257))) + (0.555570245f * fTemp409)))))) + mydsp_faustpower2_f(std::fabs(((fTemp147 + (0.923879504f * fTemp257)) - ((0.555570245f * fTemp408) + ((fTemp262 + (0.382683426f * fTemp255)) + (0.831469595f * fTemp409))))))));
			float fTemp410 = ((fTemp263 + (0.980785251f * fTemp273)) - (fTemp270 + (0.195090324f * fTemp267)));
			float fTemp411 = (fTemp286 - ((0.980785251f * fTemp267) + (fTemp288 + (0.195090324f * fTemp273))));
			output23[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp281 + (0.773010433f * fTemp410)) + (-1.0f - (((0.980785251f * fTemp278) + (fTemp292 + (0.195090324f * fTemp284))) + (0.634393275f * fTemp411)))))) + mydsp_faustpower2_f(std::fabs(((fTemp293 + (0.980785251f * fTemp284)) - ((0.634393275f * fTemp410) + ((fTemp294 + (0.195090324f * fTemp278)) + (0.773010433f * fTemp411))))))));
			output24[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp4 + (0.707106769f * fTemp296)) + (-1.0f - (fTemp301 + fTemp304))))) + mydsp_faustpower2_f(std::fabs((fTemp303 - ((0.707106769f * fTemp296) + (fTemp302 + fTemp300)))))));
			float fTemp412 = (((0.195090324f * fTemp306) + (fTemp305 + fTemp309)) - fTemp307);
			float fTemp413 = ((fTemp81 + (0.195090324f * fTemp308)) - (fTemp314 + fTemp313));
			output25[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((fTemp69 + (0.195090324f * fTemp317)) + (0.634393275f * fTemp412)) + (-1.0f - ((fTemp316 + fTemp312) + (0.773010433f * fTemp413)))))) + mydsp_faustpower2_f(std::fabs((((0.195090324f * fTemp311) + (fTemp318 + fTemp320)) - ((0.773010433f * fTemp412) + (fTemp319 + (0.634393275f * fTemp413))))))));
			float fTemp414 = (((0.382683426f * fTemp322) + (fTemp321 + (0.923879504f * fTemp325))) - fTemp323);
			float fTemp415 = ((fTemp139 + (0.382683426f * fTemp325)) - (fTemp329 + (0.923879504f * fTemp322)));
			output26[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((fTemp2 + (0.382683426f * fTemp334)) + (0.555570245f * fTemp414)) + (-1.0f - ((fTemp332 + (0.923879504f * fTemp327)) + (0.831469595f * fTemp415)))))) + mydsp_faustpower2_f(std::fabs((((0.382683426f * fTemp327) + (fTemp335 + (0.923879504f * fTemp334))) - ((0.831469595f * fTemp414) + (fTemp336 + (0.555570245f * fTemp415))))))));
			float fTemp416 = (((0.555570245f * fTemp338) + (fTemp337 + fTemp341)) - fTemp339);
			float fTemp417 = ((fTemp174 + (0.555570245f * fTemp340)) - (fTemp346 + fTemp345));
			output27[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((fTemp168 + (0.555570245f * fTemp349)) + (0.471396744f * fTemp416)) + (-1.0f - ((fTemp348 + fTemp344) + (0.881921291f * fTemp417)))))) + mydsp_faustpower2_f(std::fabs((((0.555570245f * fTemp343) + (fTemp350 + fTemp352)) - ((0.881921291f * fTemp416) + (fTemp351 + (0.471396744f * fTemp417))))))));
			float fTemp418 = (((0.707106769f * fTemp184) + (fTemp186 + fTemp404)) - fTemp182);
			float fTemp419 = ((fTemp199 + (0.707106769f * fTemp188)) - (fTemp201 + (0.707106769f * fTemp184)));
			output28[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((fTemp3 + (0.707106769f * fTemp196)) + (0.382683426f * fTemp418)) + (-1.0f - ((fTemp203 + (0.707106769f * fTemp192)) + (0.923879504f * fTemp419)))))) + mydsp_faustpower2_f(std::fabs((((0.707106769f * fTemp192) + (fTemp205 + fTemp403)) - ((0.923879504f * fTemp418) + (fTemp204 + (0.382683426f * fTemp419))))))));
			float fTemp420 = (((0.831469595f * fTemp356) + (fTemp355 + fTemp358)) - fTemp215);
			float fTemp421 = ((fTemp363 + (0.831469595f * fTemp357)) - (fTemp365 + fTemp364));
			output29[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((fTemp360 + (0.831469595f * fTemp368)) + (0.290284663f * fTemp420)) + (-1.0f - ((fTemp367 + fTemp362) + (0.956940353f * fTemp421)))))) + mydsp_faustpower2_f(std::fabs((((0.831469595f * fTemp361) + (fTemp369 + fTemp370)) - ((0.956940353f * fTemp420) + (fTemp248 + (0.290284663f * fTemp421))))))));
			float fTemp422 = (((0.923879504f * fTemp372) + (fTemp371 + (0.382683426f * fTemp373))) - fTemp91);
			float fTemp423 = ((fTemp377 + (0.923879504f * fTemp373)) - (fTemp378 + (0.382683426f * fTemp372)));
			output30[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((fTemp375 + (0.923879504f * fTemp381)) + (0.195090324f * fTemp422)) + (-1.0f - ((fTemp380 + (0.382683426f * fTemp376)) + (0.980785251f * fTemp423)))))) + mydsp_faustpower2_f(std::fabs((((0.923879504f * fTemp376) + (fTemp382 + (0.382683426f * fTemp381))) - ((0.980785251f * fTemp422) + (fTemp145 + (0.195090324f * fTemp423))))))));
			float fTemp424 = (((0.980785251f * fTemp384) + (fTemp383 + (0.195090324f * fTemp385))) - fVec0[((IOTA - 49) & 63)]);
			float fTemp425 = ((fTemp389 + (0.980785251f * fTemp385)) - (fTemp390 + (0.195090324f * fTemp384)));
			output31[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((fTemp387 + (0.980785251f * fTemp393)) + (0.0980171412f * fTemp424)) + (-1.0f - ((fTemp392 + (0.195090324f * fTemp388)) + (0.99518472f * fTemp425)))))) + mydsp_faustpower2_f(std::fabs((((0.980785251f * fTemp388) + (fTemp394 + (0.195090324f * fTemp393))) - ((0.99518472f * fTemp424) + (fVec0[((IOTA - 48) & 63)] + (0.0980171412f * fTemp425))))))));
			output32[i] = FAUSTFLOAT(mydsp_faustpower2_f(std::fabs((fTemp6 + (-1.0f - (fVec0[((IOTA - 63) & 63)] + (fVec0[((IOTA - 31) & 63)] + (fVec0[((IOTA - 47) & 63)] + (fVec0[((IOTA - 15) & 63)] + (fVec0[((IOTA - 55) & 63)] + (fVec0[((IOTA - 23) & 63)] + (fVec0[((IOTA - 39) & 63)] + (fVec0[((IOTA - 7) & 63)] + (fVec0[((IOTA - 59) & 63)] + (fVec0[((IOTA - 27) & 63)] + (fVec0[((IOTA - 43) & 63)] + (fVec0[((IOTA - 11) & 63)] + (fVec0[((IOTA - 51) & 63)] + (fVec0[((IOTA - 19) & 63)] + (fVec0[((IOTA - 35) & 63)] + (fTemp395 + fVec0[((IOTA - 3) & 63)])))))))))))))))))))));
			fRec0[1] = fRec0[0];
			IOTA = (IOTA + 1);
			
		}
		
	}

	
};

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/
					
mydsp	DSP;
	
#define kFrames 512
	
int main(int argc, char *argv[] )
{
	float fnbsamples;

	CMDUI* interface = new CMDUI(argc, argv);
	DSP.buildUserInterface(interface);
	interface->addOption("-n", &fnbsamples, 16, 0.0, 100000000.0);
	
	if (DSP.getNumInputs() > 0) {
		fprintf(stderr, "no inputs allowed\n");
		exit(1);
	}
	
	// init signal processor and the user interface values
	DSP.init(44100);
	
	// modify the UI values according to the command line options
	interface->process_command();
	
	int nouts = DSP.getNumOutputs();
	channels chan (kFrames, nouts);

	int nbsamples = int(fnbsamples);
	while (nbsamples > kFrames) {
		DSP.compute(kFrames, 0, chan.buffers());
		for (int i = 0; i < kFrames; i++) {
			for (int c = 0; c < nouts; c++) {
				printf("%8f\t", chan.buffers()[c][i]);
			}
			std::cout << std::endl;
		}
		nbsamples -= kFrames;
	}
	
	DSP.compute(nbsamples, 0, chan.buffers());
	for (int i = 0; i < nbsamples; i++) {
		for (int c = 0; c < nouts; c++) {
			printf("%8f\t", chan.buffers()[c][i]);
		}
		std::cout << std::endl;
	}
	return 0;
} 
/********************END ARCHITECTURE SECTION (part 2/2)****************/



#endif
