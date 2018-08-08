/* ------------------------------------------------------------
name: "sine"
Code generated with Faust 2.7.5 (https://faust.grame.fr)
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


class mydspSIG0 {
	
  private:
	
	int iRec0[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
		
	}
	int getNumOutputsmydspSIG0() {
		return 1;
		
	}
	int getInputRatemydspSIG0(int channel) {
		int rate;
		switch (channel) {
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	int getOutputRatemydspSIG0(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 0;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	void instanceInitmydspSIG0(int samplingFreq) {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec0[l0] = 0;
			
		}
		
	}
	
	void fillmydspSIG0(int count, float* output) {
		for (int i = 0; (i < count); i = (i + 1)) {
			iRec0[0] = std::min(1024, (iRec0[1] + 1));
			output[i] = std::sin((0.00613592332f * float(iRec0[0])));
			iRec0[1] = iRec0[0];
			
		}
		
	}
};

mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float ftbl0mydspSIG0[1024];
static float mydsp_faustpower2_f(float value) {
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
	
	float fRec1[2];
	int IOTA;
	float fVec0[64];
	int fSamplingFreq;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("filename", "sine");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "sine");
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
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(samplingFreq);
		sig0->fillmydspSIG0(1024, ftbl0mydspSIG0);
		deletemydspSIG0(sig0);
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		
	}
	
	virtual void instanceResetUserInterface() {
		
	}
	
	virtual void instanceClear() {
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
			
		}
		IOTA = 0;
		for (int l2 = 0; (l2 < 64); l2 = (l2 + 1)) {
			fVec0[l2] = 0.0f;
			
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
		ui_interface->openVerticalBox("sine");
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
			fRec1[0] = std::fmod((fRec1[1] + 0.0125000002f), 1.0f);
			float fTemp0 = (1023.0f * fRec1[0]);
			float fTemp1 = ftbl0mydspSIG0[int(fTemp0)];
			float fTemp2 = (fTemp1 + ((fTemp0 - std::floor(fTemp0)) * (fTemp1 - ftbl0mydspSIG0[(int((fTemp0 + 1.0f)) % 1023)])));
			fVec0[(IOTA & 63)] = fTemp2;
			output0[i] = FAUSTFLOAT(mydsp_faustpower2_f(std::fabs((fVec0[((IOTA - 63) & 63)] + (fVec0[((IOTA - 62) & 63)] + (fVec0[((IOTA - 61) & 63)] + (fVec0[((IOTA - 60) & 63)] + (fVec0[((IOTA - 59) & 63)] + (fVec0[((IOTA - 58) & 63)] + (fVec0[((IOTA - 57) & 63)] + (fVec0[((IOTA - 56) & 63)] + (fVec0[((IOTA - 55) & 63)] + (fVec0[((IOTA - 54) & 63)] + (fVec0[((IOTA - 53) & 63)] + (fVec0[((IOTA - 52) & 63)] + (fVec0[((IOTA - 51) & 63)] + (fVec0[((IOTA - 50) & 63)] + (fVec0[((IOTA - 49) & 63)] + (fVec0[((IOTA - 48) & 63)] + (fVec0[((IOTA - 47) & 63)] + (fVec0[((IOTA - 46) & 63)] + (fVec0[((IOTA - 45) & 63)] + (fVec0[((IOTA - 44) & 63)] + (fVec0[((IOTA - 43) & 63)] + (fVec0[((IOTA - 42) & 63)] + (fVec0[((IOTA - 41) & 63)] + (fVec0[((IOTA - 40) & 63)] + (fVec0[((IOTA - 39) & 63)] + (fVec0[((IOTA - 38) & 63)] + (fVec0[((IOTA - 37) & 63)] + (fVec0[((IOTA - 36) & 63)] + (fVec0[((IOTA - 35) & 63)] + (fVec0[((IOTA - 34) & 63)] + (fVec0[((IOTA - 33) & 63)] + (fVec0[((IOTA - 32) & 63)] + (fVec0[((IOTA - 31) & 63)] + (fVec0[((IOTA - 30) & 63)] + (fVec0[((IOTA - 29) & 63)] + (fVec0[((IOTA - 28) & 63)] + (fVec0[((IOTA - 27) & 63)] + (fVec0[((IOTA - 26) & 63)] + (fVec0[((IOTA - 25) & 63)] + (fVec0[((IOTA - 24) & 63)] + (fVec0[((IOTA - 23) & 63)] + (fVec0[((IOTA - 22) & 63)] + (fVec0[((IOTA - 21) & 63)] + (fVec0[((IOTA - 20) & 63)] + (fVec0[((IOTA - 19) & 63)] + (fVec0[((IOTA - 18) & 63)] + (fVec0[((IOTA - 17) & 63)] + (fVec0[((IOTA - 16) & 63)] + (fVec0[((IOTA - 15) & 63)] + (fVec0[((IOTA - 14) & 63)] + (fVec0[((IOTA - 13) & 63)] + (fVec0[((IOTA - 12) & 63)] + (fVec0[((IOTA - 11) & 63)] + (fVec0[((IOTA - 10) & 63)] + (fVec0[((IOTA - 9) & 63)] + (fVec0[((IOTA - 8) & 63)] + (fVec0[((IOTA - 7) & 63)] + (fVec0[((IOTA - 6) & 63)] + (fVec0[((IOTA - 5) & 63)] + (fVec0[((IOTA - 4) & 63)] + (fVec0[((IOTA - 3) & 63)] + (fVec0[((IOTA - 2) & 63)] + (fTemp2 + fVec0[((IOTA - 1) & 63)]))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
			float fTemp3 = (fVec0[((IOTA - 15) & 63)] - fVec0[((IOTA - 47) & 63)]);
			float fTemp4 = (0.707106769f * fTemp3);
			float fTemp5 = (fVec0[((IOTA - 63) & 63)] - fVec0[((IOTA - 31) & 63)]);
			float fTemp6 = (0.707106769f * fTemp5);
			float fTemp7 = ((fTemp4 + (fVec0[((IOTA - 7) & 63)] + fTemp6)) - fVec0[((IOTA - 39) & 63)]);
			float fTemp8 = (fVec0[((IOTA - 11) & 63)] - fVec0[((IOTA - 43) & 63)]);
			float fTemp9 = (0.707106769f * fTemp8);
			float fTemp10 = (0.707106769f * fTemp3);
			float fTemp11 = ((fVec0[((IOTA - 55) & 63)] + (0.707106769f * fTemp5)) - (fVec0[((IOTA - 23) & 63)] + fTemp10));
			float fTemp12 = (fVec0[((IOTA - 59) & 63)] - fVec0[((IOTA - 27) & 63)]);
			float fTemp13 = (0.707106769f * fTemp12);
			float fTemp14 = (fVec0[((IOTA - 3) & 63)] + fTemp13);
			float fTemp15 = (((0.923879504f * fTemp7) + (fTemp9 + ((0.382683426f * fTemp11) + fTemp14))) - fVec0[((IOTA - 35) & 63)]);
			float fTemp16 = (0.980785251f * fTemp15);
			float fTemp17 = (fVec0[((IOTA - 51) & 63)] + (0.707106769f * fTemp12));
			float fTemp18 = (0.707106769f * fTemp8);
			float fTemp19 = ((fTemp17 + (0.923879504f * fTemp11)) - ((fVec0[((IOTA - 19) & 63)] + fTemp18) + (0.382683426f * fTemp7)));
			float fTemp20 = (fVec0[((IOTA - 13) & 63)] - fVec0[((IOTA - 45) & 63)]);
			float fTemp21 = (0.707106769f * fTemp20);
			float fTemp22 = (fVec0[((IOTA - 61) & 63)] - fVec0[((IOTA - 29) & 63)]);
			float fTemp23 = (0.707106769f * fTemp22);
			float fTemp24 = ((fTemp21 + (fVec0[((IOTA - 5) & 63)] + fTemp23)) - fVec0[((IOTA - 37) & 63)]);
			float fTemp25 = (fVec0[((IOTA - 9) & 63)] - fVec0[((IOTA - 41) & 63)]);
			float fTemp26 = (0.707106769f * fTemp25);
			float fTemp27 = (0.707106769f * fTemp20);
			float fTemp28 = ((fVec0[((IOTA - 53) & 63)] + (0.707106769f * fTemp22)) - (fVec0[((IOTA - 21) & 63)] + fTemp27));
			float fTemp29 = (fVec0[((IOTA - 57) & 63)] - fVec0[((IOTA - 25) & 63)]);
			float fTemp30 = (0.707106769f * fTemp29);
			float fTemp31 = (fVec0[((IOTA - 1) & 63)] + fTemp30);
			float fTemp32 = ((0.923879504f * fTemp24) + (fTemp26 + ((0.382683426f * fTemp28) + fTemp31)));
			float fTemp33 = ((fTemp16 + ((0.195090324f * fTemp19) + fTemp32)) - fVec0[((IOTA - 33) & 63)]);
			float fTemp34 = (0.980785251f * fTemp19);
			float fTemp35 = (fVec0[((IOTA - 49) & 63)] + (0.707106769f * fTemp29));
			float fTemp36 = ((0.923879504f * fTemp28) + fTemp35);
			float fTemp37 = (0.707106769f * fTemp25);
			float fTemp38 = ((0.382683426f * fTemp24) + (fVec0[((IOTA - 17) & 63)] + fTemp37));
			float fTemp39 = ((fTemp34 + fTemp36) - ((0.195090324f * fTemp15) + fTemp38));
			float fTemp40 = (fVec0[((IOTA - 14) & 63)] - fVec0[((IOTA - 46) & 63)]);
			float fTemp41 = (0.707106769f * fTemp40);
			float fTemp42 = (fVec0[((IOTA - 62) & 63)] - fVec0[((IOTA - 30) & 63)]);
			float fTemp43 = (0.707106769f * fTemp42);
			float fTemp44 = ((fTemp41 + (fVec0[((IOTA - 6) & 63)] + fTemp43)) - fVec0[((IOTA - 38) & 63)]);
			float fTemp45 = (fVec0[((IOTA - 10) & 63)] - fVec0[((IOTA - 42) & 63)]);
			float fTemp46 = (0.707106769f * fTemp45);
			float fTemp47 = (0.707106769f * fTemp40);
			float fTemp48 = ((fVec0[((IOTA - 54) & 63)] + (0.707106769f * fTemp42)) - (fVec0[((IOTA - 22) & 63)] + fTemp47));
			float fTemp49 = (fVec0[((IOTA - 58) & 63)] - fVec0[((IOTA - 26) & 63)]);
			float fTemp50 = (0.707106769f * fTemp49);
			float fTemp51 = (fVec0[((IOTA - 2) & 63)] + fTemp50);
			float fTemp52 = (((0.923879504f * fTemp44) + (fTemp46 + ((0.382683426f * fTemp48) + fTemp51))) - fVec0[((IOTA - 34) & 63)]);
			float fTemp53 = (0.980785251f * fTemp52);
			float fTemp54 = (fVec0[((IOTA - 50) & 63)] + (0.707106769f * fTemp49));
			float fTemp55 = (0.707106769f * fTemp45);
			float fTemp56 = (((0.923879504f * fTemp48) + fTemp54) - ((0.382683426f * fTemp44) + (fVec0[((IOTA - 18) & 63)] + fTemp55)));
			float fTemp57 = (fVec0[((IOTA - 12) & 63)] - fVec0[((IOTA - 44) & 63)]);
			float fTemp58 = (0.707106769f * fTemp57);
			float fTemp59 = (fVec0[((IOTA - 60) & 63)] - fVec0[((IOTA - 28) & 63)]);
			float fTemp60 = (0.707106769f * fTemp59);
			float fTemp61 = ((fTemp58 + (fVec0[((IOTA - 4) & 63)] + fTemp60)) - fVec0[((IOTA - 36) & 63)]);
			float fTemp62 = (0.707106769f * fTemp57);
			float fTemp63 = ((fVec0[((IOTA - 52) & 63)] + (0.707106769f * fTemp59)) - (fVec0[((IOTA - 20) & 63)] + fTemp62));
			float fTemp64 = (fVec0[((IOTA - 56) & 63)] - fVec0[((IOTA - 24) & 63)]);
			float fTemp65 = (0.707106769f * fTemp64);
			float fTemp66 = (fVec0[((IOTA - 8) & 63)] - fVec0[((IOTA - 40) & 63)]);
			float fTemp67 = (0.707106769f * fTemp66);
			float fTemp68 = (fTemp65 + (fTemp2 + fTemp67));
			float fTemp69 = ((0.923879504f * fTemp61) + ((0.382683426f * fTemp63) + fTemp68));
			float fTemp70 = (0.980785251f * fTemp56);
			float fTemp71 = (fVec0[((IOTA - 48) & 63)] + (0.707106769f * fTemp64));
			float fTemp72 = ((0.923879504f * fTemp63) + fTemp71);
			float fTemp73 = (0.707106769f * fTemp66);
			float fTemp74 = (fVec0[((IOTA - 16) & 63)] + fTemp73);
			float fTemp75 = ((0.382683426f * fTemp61) + fTemp74);
			output1[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.99518472f * fTemp33) + ((0.0980171412f * fTemp39) + (fTemp53 + ((0.195090324f * fTemp56) + fTemp69)))) - fVec0[((IOTA - 32) & 63)]))) + mydsp_faustpower2_f(std::fabs((((0.99518472f * fTemp39) + (fTemp70 + fTemp72)) - ((0.0980171412f * fTemp33) + ((0.195090324f * fTemp52) + fTemp75)))))));
			float fTemp76 = ((fVec0[((IOTA - 7) & 63)] + fVec0[((IOTA - 39) & 63)]) - (fVec0[((IOTA - 23) & 63)] + fVec0[((IOTA - 55) & 63)]));
			float fTemp77 = (0.707106769f * fTemp76);
			float fTemp78 = (fVec0[((IOTA - 3) & 63)] + fVec0[((IOTA - 35) & 63)]);
			float fTemp79 = (fVec0[((IOTA - 31) & 63)] + fVec0[((IOTA - 63) & 63)]);
			float fTemp80 = (fVec0[((IOTA - 15) & 63)] + fVec0[((IOTA - 47) & 63)]);
			float fTemp81 = (fTemp79 - fTemp80);
			float fTemp82 = (0.707106769f * fTemp81);
			float fTemp83 = (fVec0[((IOTA - 19) & 63)] + fVec0[((IOTA - 51) & 63)]);
			float fTemp84 = ((fTemp77 + (fTemp78 + fTemp82)) - fTemp83);
			float fTemp85 = ((fVec0[((IOTA - 5) & 63)] + fVec0[((IOTA - 37) & 63)]) - (fVec0[((IOTA - 21) & 63)] + fVec0[((IOTA - 53) & 63)]));
			float fTemp86 = (0.707106769f * fTemp85);
			float fTemp87 = (fVec0[((IOTA - 27) & 63)] + fVec0[((IOTA - 59) & 63)]);
			float fTemp88 = (fVec0[((IOTA - 11) & 63)] + fVec0[((IOTA - 43) & 63)]);
			float fTemp89 = (0.707106769f * fTemp76);
			float fTemp90 = ((fTemp87 + (0.707106769f * fTemp81)) - (fTemp88 + fTemp89));
			float fTemp91 = (fVec0[((IOTA - 29) & 63)] + fVec0[((IOTA - 61) & 63)]);
			float fTemp92 = (fVec0[((IOTA - 13) & 63)] + fVec0[((IOTA - 45) & 63)]);
			float fTemp93 = (fTemp91 - fTemp92);
			float fTemp94 = (0.707106769f * fTemp93);
			float fTemp95 = (fVec0[((IOTA - 1) & 63)] + fVec0[((IOTA - 33) & 63)]);
			float fTemp96 = (fTemp94 + fTemp95);
			float fTemp97 = (fVec0[((IOTA - 17) & 63)] + fVec0[((IOTA - 49) & 63)]);
			float fTemp98 = (((0.923879504f * fTemp84) + (fTemp86 + ((0.382683426f * fTemp90) + fTemp96))) - fTemp97);
			float fTemp99 = (fVec0[((IOTA - 25) & 63)] + fVec0[((IOTA - 57) & 63)]);
			float fTemp100 = ((0.707106769f * fTemp93) + fTemp99);
			float fTemp101 = (0.707106769f * fTemp85);
			float fTemp102 = (fVec0[((IOTA - 9) & 63)] + fVec0[((IOTA - 41) & 63)]);
			float fTemp103 = (((0.923879504f * fTemp90) + fTemp100) - ((0.382683426f * fTemp84) + (fTemp101 + fTemp102)));
			float fTemp104 = ((fVec0[((IOTA - 6) & 63)] + fVec0[((IOTA - 38) & 63)]) - (fVec0[((IOTA - 22) & 63)] + fVec0[((IOTA - 54) & 63)]));
			float fTemp105 = (0.707106769f * fTemp104);
			float fTemp106 = (fVec0[((IOTA - 30) & 63)] + fVec0[((IOTA - 62) & 63)]);
			float fTemp107 = (fVec0[((IOTA - 14) & 63)] + fVec0[((IOTA - 46) & 63)]);
			float fTemp108 = (fTemp106 - fTemp107);
			float fTemp109 = (0.707106769f * fTemp108);
			float fTemp110 = (fVec0[((IOTA - 2) & 63)] + fVec0[((IOTA - 34) & 63)]);
			float fTemp111 = (fVec0[((IOTA - 18) & 63)] + fVec0[((IOTA - 50) & 63)]);
			float fTemp112 = ((fTemp105 + (fTemp109 + fTemp110)) - fTemp111);
			float fTemp113 = (fVec0[((IOTA - 26) & 63)] + fVec0[((IOTA - 58) & 63)]);
			float fTemp114 = (0.707106769f * fTemp104);
			float fTemp115 = (fVec0[((IOTA - 10) & 63)] + fVec0[((IOTA - 42) & 63)]);
			float fTemp116 = (((0.707106769f * fTemp108) + fTemp113) - (fTemp114 + fTemp115));
			float fTemp117 = (fVec0[((IOTA - 28) & 63)] + fVec0[((IOTA - 60) & 63)]);
			float fTemp118 = (fVec0[((IOTA - 12) & 63)] + fVec0[((IOTA - 44) & 63)]);
			float fTemp119 = (fTemp117 - fTemp118);
			float fTemp120 = (0.707106769f * fTemp119);
			float fTemp121 = (fTemp2 + fVec0[((IOTA - 32) & 63)]);
			float fTemp122 = ((fVec0[((IOTA - 4) & 63)] + fVec0[((IOTA - 36) & 63)]) - (fVec0[((IOTA - 20) & 63)] + fVec0[((IOTA - 52) & 63)]));
			float fTemp123 = (0.707106769f * fTemp122);
			float fTemp124 = (fTemp120 + (fTemp121 + fTemp123));
			float fTemp125 = (fVec0[((IOTA - 16) & 63)] + fVec0[((IOTA - 48) & 63)]);
			float fTemp126 = (fVec0[((IOTA - 24) & 63)] + fVec0[((IOTA - 56) & 63)]);
			float fTemp127 = ((0.707106769f * fTemp119) + fTemp126);
			float fTemp128 = (0.707106769f * fTemp122);
			float fTemp129 = (fVec0[((IOTA - 8) & 63)] + fVec0[((IOTA - 40) & 63)]);
			float fTemp130 = (fTemp128 + fTemp129);
			output2[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.980785251f * fTemp98) + ((0.195090324f * fTemp103) + ((0.923879504f * fTemp112) + ((0.382683426f * fTemp116) + fTemp124)))) - fTemp125))) + mydsp_faustpower2_f(std::fabs((((0.980785251f * fTemp103) + ((0.923879504f * fTemp116) + fTemp127)) - ((0.195090324f * fTemp98) + ((0.382683426f * fTemp112) + fTemp130)))))));
			float fTemp131 = (fVec0[((IOTA - 31) & 63)] - fVec0[((IOTA - 63) & 63)]);
			float fTemp132 = ((fVec0[((IOTA - 7) & 63)] + (0.707106769f * fTemp131)) - (fVec0[((IOTA - 39) & 63)] + fTemp10));
			float fTemp133 = (fVec0[((IOTA - 27) & 63)] - fVec0[((IOTA - 59) & 63)]);
			float fTemp134 = (0.707106769f * fTemp133);
			float fTemp135 = (fVec0[((IOTA - 23) & 63)] - ((fVec0[((IOTA - 55) & 63)] + fTemp4) + (0.707106769f * fTemp131)));
			float fTemp136 = (fVec0[((IOTA - 35) & 63)] + fTemp18);
			float fTemp137 = (((0.382683426f * fTemp132) + (fTemp134 + (fVec0[((IOTA - 3) & 63)] + (0.923879504f * fTemp135)))) - fTemp136);
			float fTemp138 = (fVec0[((IOTA - 29) & 63)] - fVec0[((IOTA - 61) & 63)]);
			float fTemp139 = (fVec0[((IOTA - 21) & 63)] - ((0.707106769f * fTemp138) + (fVec0[((IOTA - 53) & 63)] + fTemp21)));
			float fTemp140 = (0.923879504f * fTemp139);
			float fTemp141 = ((fVec0[((IOTA - 5) & 63)] + (0.707106769f * fTemp138)) - (fVec0[((IOTA - 37) & 63)] + fTemp27));
			float fTemp142 = (0.382683426f * fTemp141);
			float fTemp143 = (fVec0[((IOTA - 25) & 63)] - fVec0[((IOTA - 57) & 63)]);
			float fTemp144 = (0.707106769f * fTemp143);
			float fTemp145 = (fVec0[((IOTA - 51) & 63)] + fTemp9);
			float fTemp146 = (0.707106769f * fTemp133);
			float fTemp147 = ((fVec0[((IOTA - 19) & 63)] + (0.382683426f * fTemp135)) - ((fTemp145 + fTemp146) + (0.923879504f * fTemp132)));
			float fTemp148 = (fVec0[((IOTA - 33) & 63)] + fTemp37);
			float fTemp149 = (((0.831469595f * fTemp137) + (fTemp140 + (fTemp142 + (fTemp144 + (fVec0[((IOTA - 1) & 63)] + (0.555570245f * fTemp147)))))) - fTemp148);
			float fTemp150 = (0.382683426f * fTemp139);
			float fTemp151 = (0.923879504f * fTemp141);
			float fTemp152 = (0.707106769f * fTemp143);
			float fTemp153 = (fVec0[((IOTA - 49) & 63)] + fTemp26);
			float fTemp154 = (fTemp152 + fTemp153);
			float fTemp155 = (((fVec0[((IOTA - 17) & 63)] + (0.831469595f * fTemp147)) + fTemp150) - ((0.555570245f * fTemp137) + (fTemp151 + fTemp154)));
			float fTemp156 = (fVec0[((IOTA - 30) & 63)] - fVec0[((IOTA - 62) & 63)]);
			float fTemp157 = (fVec0[((IOTA - 22) & 63)] - ((0.707106769f * fTemp156) + (fVec0[((IOTA - 54) & 63)] + fTemp41)));
			float fTemp158 = ((fVec0[((IOTA - 6) & 63)] + (0.707106769f * fTemp156)) - (fVec0[((IOTA - 38) & 63)] + fTemp47));
			float fTemp159 = (fVec0[((IOTA - 26) & 63)] - fVec0[((IOTA - 58) & 63)]);
			float fTemp160 = (fVec0[((IOTA - 2) & 63)] + (0.707106769f * fTemp159));
			float fTemp161 = (fVec0[((IOTA - 34) & 63)] + fTemp55);
			float fTemp162 = (((0.923879504f * fTemp157) + ((0.382683426f * fTemp158) + fTemp160)) - fTemp161);
			float fTemp163 = ((0.707106769f * fTemp159) + (fVec0[((IOTA - 50) & 63)] + fTemp46));
			float fTemp164 = ((fVec0[((IOTA - 18) & 63)] + (0.382683426f * fTemp157)) - ((0.923879504f * fTemp158) + fTemp163));
			float fTemp165 = (fVec0[((IOTA - 28) & 63)] - fVec0[((IOTA - 60) & 63)]);
			float fTemp166 = (fVec0[((IOTA - 20) & 63)] - ((0.707106769f * fTemp165) + (fVec0[((IOTA - 52) & 63)] + fTemp58)));
			float fTemp167 = ((fVec0[((IOTA - 4) & 63)] + (0.707106769f * fTemp165)) - (fVec0[((IOTA - 36) & 63)] + fTemp62));
			float fTemp168 = (fVec0[((IOTA - 24) & 63)] - fVec0[((IOTA - 56) & 63)]);
			float fTemp169 = (fTemp2 + (0.707106769f * fTemp168));
			float fTemp170 = ((0.923879504f * fTemp166) + ((0.382683426f * fTemp167) + fTemp169));
			float fTemp171 = (fVec0[((IOTA - 32) & 63)] + fTemp73);
			float fTemp172 = (fVec0[((IOTA - 16) & 63)] + (0.382683426f * fTemp166));
			float fTemp173 = ((0.707106769f * fTemp168) + (fVec0[((IOTA - 48) & 63)] + fTemp67));
			float fTemp174 = ((0.923879504f * fTemp167) + fTemp173);
			output3[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.956940353f * fTemp149) + ((0.290284663f * fTemp155) + ((0.831469595f * fTemp162) + ((0.555570245f * fTemp164) + fTemp170)))) - fTemp171))) + mydsp_faustpower2_f(std::fabs((((0.956940353f * fTemp155) + ((0.831469595f * fTemp164) + fTemp172)) - ((0.290284663f * fTemp149) + ((0.555570245f * fTemp162) + fTemp174)))))));
			float fTemp175 = ((fVec0[((IOTA - 51) & 63)] + (fVec0[((IOTA - 35) & 63)] + (fVec0[((IOTA - 3) & 63)] + fVec0[((IOTA - 19) & 63)]))) - (fVec0[((IOTA - 59) & 63)] + (fVec0[((IOTA - 43) & 63)] + (fVec0[((IOTA - 11) & 63)] + fVec0[((IOTA - 27) & 63)]))));
			float fTemp176 = (0.707106769f * fTemp175);
			float fTemp177 = (fVec0[((IOTA - 63) & 63)] + (fVec0[((IOTA - 47) & 63)] + (fVec0[((IOTA - 15) & 63)] + fVec0[((IOTA - 31) & 63)])));
			float fTemp178 = (fVec0[((IOTA - 55) & 63)] + (fVec0[((IOTA - 39) & 63)] + (fVec0[((IOTA - 7) & 63)] + fVec0[((IOTA - 23) & 63)])));
			float fTemp179 = (fTemp177 - fTemp178);
			float fTemp180 = (0.707106769f * fTemp179);
			float fTemp181 = (fVec0[((IOTA - 49) & 63)] + (fVec0[((IOTA - 33) & 63)] + (fVec0[((IOTA - 1) & 63)] + fVec0[((IOTA - 17) & 63)])));
			float fTemp182 = (fVec0[((IOTA - 57) & 63)] + (fVec0[((IOTA - 41) & 63)] + (fVec0[((IOTA - 9) & 63)] + fVec0[((IOTA - 25) & 63)])));
			float fTemp183 = ((fTemp176 + (fTemp180 + fTemp181)) - fTemp182);
			float fTemp184 = (fVec0[((IOTA - 61) & 63)] + (fVec0[((IOTA - 45) & 63)] + (fVec0[((IOTA - 13) & 63)] + fVec0[((IOTA - 29) & 63)])));
			float fTemp185 = (0.707106769f * fTemp175);
			float fTemp186 = (fVec0[((IOTA - 53) & 63)] + (fVec0[((IOTA - 37) & 63)] + (fVec0[((IOTA - 5) & 63)] + fVec0[((IOTA - 21) & 63)])));
			float fTemp187 = (((0.707106769f * fTemp179) + fTemp184) - (fTemp185 + fTemp186));
			float fTemp188 = (fVec0[((IOTA - 62) & 63)] + (fVec0[((IOTA - 46) & 63)] + (fVec0[((IOTA - 14) & 63)] + fVec0[((IOTA - 30) & 63)])));
			float fTemp189 = (fVec0[((IOTA - 54) & 63)] + (fVec0[((IOTA - 38) & 63)] + (fVec0[((IOTA - 6) & 63)] + fVec0[((IOTA - 22) & 63)])));
			float fTemp190 = (fTemp188 - fTemp189);
			float fTemp191 = (0.707106769f * fTemp190);
			float fTemp192 = ((fVec0[((IOTA - 50) & 63)] + (fVec0[((IOTA - 34) & 63)] + (fVec0[((IOTA - 2) & 63)] + fVec0[((IOTA - 18) & 63)]))) - (fVec0[((IOTA - 58) & 63)] + (fVec0[((IOTA - 42) & 63)] + (fVec0[((IOTA - 10) & 63)] + fVec0[((IOTA - 26) & 63)]))));
			float fTemp193 = (0.707106769f * fTemp192);
			float fTemp194 = (fVec0[((IOTA - 48) & 63)] + (fVec0[((IOTA - 32) & 63)] + (fTemp2 + fVec0[((IOTA - 16) & 63)])));
			float fTemp195 = (fVec0[((IOTA - 56) & 63)] + (fVec0[((IOTA - 40) & 63)] + (fVec0[((IOTA - 8) & 63)] + fVec0[((IOTA - 24) & 63)])));
			float fTemp196 = (fVec0[((IOTA - 60) & 63)] + (fVec0[((IOTA - 44) & 63)] + (fVec0[((IOTA - 12) & 63)] + fVec0[((IOTA - 28) & 63)])));
			float fTemp197 = (0.707106769f * fTemp192);
			float fTemp198 = (fVec0[((IOTA - 52) & 63)] + (fVec0[((IOTA - 36) & 63)] + (fVec0[((IOTA - 4) & 63)] + fVec0[((IOTA - 20) & 63)])));
			output4[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.923879504f * fTemp183) + ((0.382683426f * fTemp187) + (fTemp191 + (fTemp193 + fTemp194)))) - fTemp195))) + mydsp_faustpower2_f(std::fabs((((0.923879504f * fTemp187) + ((0.707106769f * fTemp190) + fTemp196)) - ((0.382683426f * fTemp183) + (fTemp197 + fTemp198)))))));
			float fTemp199 = ((fVec0[((IOTA - 55) & 63)] + fTemp10) - (fVec0[((IOTA - 23) & 63)] + (0.707106769f * fTemp5)));
			float fTemp200 = (0.707106769f * fTemp8);
			float fTemp201 = (fTemp200 + (fVec0[((IOTA - 35) & 63)] + fTemp13));
			float fTemp202 = (0.707106769f * fTemp3);
			float fTemp203 = (fVec0[((IOTA - 7) & 63)] - (fTemp202 + (fVec0[((IOTA - 39) & 63)] + fTemp6)));
			float fTemp204 = ((fVec0[((IOTA - 3) & 63)] + (0.923879504f * fTemp199)) - (fTemp201 + (0.382683426f * fTemp203)));
			float fTemp205 = ((fVec0[((IOTA - 53) & 63)] + fTemp27) - (fVec0[((IOTA - 21) & 63)] + (0.707106769f * fTemp22)));
			float fTemp206 = (fVec0[((IOTA - 1) & 63)] + (0.923879504f * fTemp205));
			float fTemp207 = (fVec0[((IOTA - 51) & 63)] + fTemp18);
			float fTemp208 = (fVec0[((IOTA - 19) & 63)] + (0.707106769f * fTemp12));
			float fTemp209 = (fTemp207 - ((0.923879504f * fTemp203) + (fTemp208 + (0.382683426f * fTemp199))));
			float fTemp210 = (0.831469595f * fTemp209);
			float fTemp211 = (0.707106769f * fTemp20);
			float fTemp212 = (fVec0[((IOTA - 5) & 63)] - (fTemp211 + (fVec0[((IOTA - 37) & 63)] + fTemp23)));
			float fTemp213 = (0.707106769f * fTemp25);
			float fTemp214 = (fTemp213 + (fVec0[((IOTA - 33) & 63)] + fTemp30));
			float fTemp215 = ((0.382683426f * fTemp212) + fTemp214);
			float fTemp216 = (((0.555570245f * fTemp204) + (fTemp206 + fTemp210)) - fTemp215);
			float fTemp217 = (fVec0[((IOTA - 49) & 63)] + fTemp37);
			float fTemp218 = (0.831469595f * fTemp204);
			float fTemp219 = (fVec0[((IOTA - 17) & 63)] + (0.707106769f * fTemp29));
			float fTemp220 = ((0.923879504f * fTemp212) + ((0.382683426f * fTemp205) + fTemp219));
			float fTemp221 = (((0.555570245f * fTemp209) + fTemp217) - (fTemp218 + fTemp220));
			float fTemp222 = ((fVec0[((IOTA - 54) & 63)] + fTemp47) - (fVec0[((IOTA - 22) & 63)] + (0.707106769f * fTemp42)));
			float fTemp223 = (0.707106769f * fTemp40);
			float fTemp224 = (fVec0[((IOTA - 6) & 63)] - (fTemp223 + (fVec0[((IOTA - 38) & 63)] + fTemp43)));
			float fTemp225 = (0.707106769f * fTemp45);
			float fTemp226 = (fTemp225 + (fVec0[((IOTA - 34) & 63)] + fTemp50));
			float fTemp227 = ((fVec0[((IOTA - 2) & 63)] + (0.923879504f * fTemp222)) - ((0.382683426f * fTemp224) + fTemp226));
			float fTemp228 = (fVec0[((IOTA - 50) & 63)] + fTemp55);
			float fTemp229 = (fVec0[((IOTA - 18) & 63)] + (0.707106769f * fTemp49));
			float fTemp230 = (fTemp228 - ((0.923879504f * fTemp224) + ((0.382683426f * fTemp222) + fTemp229)));
			float fTemp231 = (0.831469595f * fTemp230);
			float fTemp232 = ((fVec0[((IOTA - 52) & 63)] + fTemp62) - (fVec0[((IOTA - 20) & 63)] + (0.707106769f * fTemp59)));
			float fTemp233 = (fTemp2 + (0.923879504f * fTemp232));
			float fTemp234 = (0.707106769f * fTemp57);
			float fTemp235 = (fVec0[((IOTA - 4) & 63)] - (fTemp234 + (fVec0[((IOTA - 36) & 63)] + fTemp60)));
			float fTemp236 = (0.707106769f * fTemp66);
			float fTemp237 = (fTemp65 + (fVec0[((IOTA - 32) & 63)] + fTemp236));
			float fTemp238 = ((0.382683426f * fTemp235) + fTemp237);
			float fTemp239 = (fVec0[((IOTA - 48) & 63)] + fTemp73);
			float fTemp240 = (0.831469595f * fTemp227);
			float fTemp241 = (fVec0[((IOTA - 16) & 63)] + (0.707106769f * fTemp64));
			float fTemp242 = ((0.923879504f * fTemp235) + ((0.382683426f * fTemp232) + fTemp241));
			output5[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.881921291f * fTemp216) + ((0.471396744f * fTemp221) + ((0.555570245f * fTemp227) + (fTemp231 + fTemp233)))) - fTemp238))) + mydsp_faustpower2_f(std::fabs((((0.881921291f * fTemp221) + ((0.555570245f * fTemp230) + fTemp239)) - ((0.471396744f * fTemp216) + (fTemp240 + fTemp242)))))));
			float fTemp243 = (fTemp80 - fTemp79);
			float fTemp244 = ((fTemp78 + (0.707106769f * fTemp243)) - (fTemp89 + fTemp83));
			float fTemp245 = (fTemp92 - fTemp91);
			float fTemp246 = (0.707106769f * fTemp245);
			float fTemp247 = (fTemp88 - ((fTemp87 + fTemp77) + (0.707106769f * fTemp243)));
			float fTemp248 = (fTemp101 + fTemp97);
			float fTemp249 = (((0.382683426f * fTemp244) + (fTemp246 + (fTemp95 + (0.923879504f * fTemp247)))) - fTemp248);
			float fTemp250 = (0.707106769f * fTemp245);
			float fTemp251 = (fTemp99 + fTemp86);
			float fTemp252 = ((fTemp102 + (0.382683426f * fTemp247)) - ((0.923879504f * fTemp244) + (fTemp250 + fTemp251)));
			float fTemp253 = (fTemp107 - fTemp106);
			float fTemp254 = ((fTemp110 + (0.707106769f * fTemp253)) - (fTemp114 + fTemp111));
			float fTemp255 = (fTemp115 - ((0.707106769f * fTemp253) + (fTemp113 + fTemp105)));
			float fTemp256 = (fTemp118 - fTemp117);
			float fTemp257 = (fTemp121 + (0.707106769f * fTemp256));
			float fTemp258 = (fTemp125 + fTemp128);
			float fTemp259 = ((0.707106769f * fTemp256) + (fTemp123 + fTemp126));
			output6[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.831469595f * fTemp249) + ((0.555570245f * fTemp252) + ((0.382683426f * fTemp254) + ((0.923879504f * fTemp255) + fTemp257)))) - fTemp258))) + mydsp_faustpower2_f(std::fabs((((0.831469595f * fTemp252) + (fTemp129 + (0.382683426f * fTemp255))) - ((0.555570245f * fTemp249) + ((0.923879504f * fTemp254) + fTemp259)))))));
			float fTemp260 = (((0.707106769f * fTemp138) + (fVec0[((IOTA - 21) & 63)] + fTemp211)) - fVec0[((IOTA - 53) & 63)]);
			float fTemp261 = (0.382683426f * fTemp260);
			float fTemp262 = (fVec0[((IOTA - 3) & 63)] + (0.707106769f * fTemp8));
			float fTemp263 = (((fVec0[((IOTA - 23) & 63)] + fTemp202) + (0.707106769f * fTemp131)) - fVec0[((IOTA - 55) & 63)]);
			float fTemp264 = (fVec0[((IOTA - 35) & 63)] + (0.707106769f * fTemp133));
			float fTemp265 = ((fVec0[((IOTA - 7) & 63)] + (0.707106769f * fTemp3)) - (fVec0[((IOTA - 39) & 63)] + (0.707106769f * fTemp131)));
			float fTemp266 = ((fTemp262 + (0.382683426f * fTemp263)) - (fTemp264 + (0.923879504f * fTemp265)));
			float fTemp267 = ((fVec0[((IOTA - 19) & 63)] + fTemp200) + (0.707106769f * fTemp133));
			float fTemp268 = (fTemp267 - ((fVec0[((IOTA - 51) & 63)] + (0.382683426f * fTemp265)) + (0.923879504f * fTemp263)));
			float fTemp269 = (fVec0[((IOTA - 1) & 63)] + (0.707106769f * fTemp25));
			float fTemp270 = ((fVec0[((IOTA - 5) & 63)] + (0.707106769f * fTemp20)) - (fVec0[((IOTA - 37) & 63)] + (0.707106769f * fTemp138)));
			float fTemp271 = (0.923879504f * fTemp270);
			float fTemp272 = (fVec0[((IOTA - 33) & 63)] + (0.707106769f * fTemp143));
			float fTemp273 = ((fTemp261 + ((0.195090324f * fTemp266) + ((0.980785251f * fTemp268) + fTemp269))) - (fTemp271 + fTemp272));
			float fTemp274 = ((0.707106769f * fTemp143) + (fVec0[((IOTA - 17) & 63)] + fTemp213));
			float fTemp275 = (0.923879504f * fTemp260);
			float fTemp276 = (0.382683426f * fTemp270);
			float fTemp277 = (((0.195090324f * fTemp268) + fTemp274) - (fTemp275 + ((0.980785251f * fTemp266) + (fVec0[((IOTA - 49) & 63)] + fTemp276))));
			float fTemp278 = (((0.707106769f * fTemp156) + (fVec0[((IOTA - 22) & 63)] + fTemp223)) - fVec0[((IOTA - 54) & 63)]);
			float fTemp279 = (fVec0[((IOTA - 2) & 63)] + (0.707106769f * fTemp45));
			float fTemp280 = ((fVec0[((IOTA - 6) & 63)] + (0.707106769f * fTemp40)) - (fVec0[((IOTA - 38) & 63)] + (0.707106769f * fTemp156)));
			float fTemp281 = (fVec0[((IOTA - 34) & 63)] + (0.707106769f * fTemp159));
			float fTemp282 = (((0.382683426f * fTemp278) + fTemp279) - ((0.923879504f * fTemp280) + fTemp281));
			float fTemp283 = ((0.707106769f * fTemp159) + (fVec0[((IOTA - 18) & 63)] + fTemp225));
			float fTemp284 = (fTemp283 - ((fVec0[((IOTA - 50) & 63)] + (0.382683426f * fTemp280)) + (0.923879504f * fTemp278)));
			float fTemp285 = (((0.707106769f * fTemp165) + (fVec0[((IOTA - 20) & 63)] + fTemp234)) - fVec0[((IOTA - 52) & 63)]);
			float fTemp286 = (fTemp2 + (0.707106769f * fTemp66));
			float fTemp287 = ((0.382683426f * fTemp285) + fTemp286);
			float fTemp288 = ((fVec0[((IOTA - 4) & 63)] + (0.707106769f * fTemp57)) - (fVec0[((IOTA - 36) & 63)] + (0.707106769f * fTemp165)));
			float fTemp289 = (fVec0[((IOTA - 32) & 63)] + (0.707106769f * fTemp168));
			float fTemp290 = ((0.923879504f * fTemp288) + fTemp289);
			float fTemp291 = ((0.707106769f * fTemp168) + (fVec0[((IOTA - 16) & 63)] + fTemp236));
			float fTemp292 = ((0.923879504f * fTemp285) + (fVec0[((IOTA - 48) & 63)] + (0.382683426f * fTemp288)));
			output7[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.773010433f * fTemp273) + ((0.634393275f * fTemp277) + ((0.195090324f * fTemp282) + ((0.980785251f * fTemp284) + fTemp287)))) - fTemp290))) + mydsp_faustpower2_f(std::fabs((((0.773010433f * fTemp277) + ((0.195090324f * fTemp284) + fTemp291)) - ((0.634393275f * fTemp273) + ((0.980785251f * fTemp282) + fTemp292)))))));
			float fTemp293 = (fVec0[((IOTA - 63) & 63)] + (fVec0[((IOTA - 55) & 63)] + (fVec0[((IOTA - 47) & 63)] + (fVec0[((IOTA - 39) & 63)] + (fVec0[((IOTA - 31) & 63)] + (fVec0[((IOTA - 23) & 63)] + (fVec0[((IOTA - 7) & 63)] + fVec0[((IOTA - 15) & 63)])))))));
			float fTemp294 = (fVec0[((IOTA - 59) & 63)] + (fVec0[((IOTA - 51) & 63)] + (fVec0[((IOTA - 43) & 63)] + (fVec0[((IOTA - 35) & 63)] + (fVec0[((IOTA - 27) & 63)] + (fVec0[((IOTA - 19) & 63)] + (fVec0[((IOTA - 3) & 63)] + fVec0[((IOTA - 11) & 63)])))))));
			float fTemp295 = (fTemp293 - fTemp294);
			float fTemp296 = ((fVec0[((IOTA - 57) & 63)] + (fVec0[((IOTA - 49) & 63)] + (fVec0[((IOTA - 41) & 63)] + (fVec0[((IOTA - 33) & 63)] + (fVec0[((IOTA - 25) & 63)] + (fVec0[((IOTA - 17) & 63)] + (fVec0[((IOTA - 1) & 63)] + fVec0[((IOTA - 9) & 63)]))))))) - (fVec0[((IOTA - 61) & 63)] + (fVec0[((IOTA - 53) & 63)] + (fVec0[((IOTA - 45) & 63)] + (fVec0[((IOTA - 37) & 63)] + (fVec0[((IOTA - 29) & 63)] + (fVec0[((IOTA - 21) & 63)] + (fVec0[((IOTA - 5) & 63)] + fVec0[((IOTA - 13) & 63)]))))))));
			float fTemp297 = (0.707106769f * fTemp296);
			float fTemp298 = (fVec0[((IOTA - 56) & 63)] + (fVec0[((IOTA - 48) & 63)] + (fVec0[((IOTA - 40) & 63)] + (fVec0[((IOTA - 32) & 63)] + (fVec0[((IOTA - 24) & 63)] + (fVec0[((IOTA - 16) & 63)] + (fTemp2 + fVec0[((IOTA - 8) & 63)])))))));
			float fTemp299 = (fVec0[((IOTA - 60) & 63)] + (fVec0[((IOTA - 52) & 63)] + (fVec0[((IOTA - 44) & 63)] + (fVec0[((IOTA - 36) & 63)] + (fVec0[((IOTA - 28) & 63)] + (fVec0[((IOTA - 20) & 63)] + (fVec0[((IOTA - 4) & 63)] + fVec0[((IOTA - 12) & 63)])))))));
			float fTemp300 = (fVec0[((IOTA - 62) & 63)] + (fVec0[((IOTA - 54) & 63)] + (fVec0[((IOTA - 46) & 63)] + (fVec0[((IOTA - 38) & 63)] + (fVec0[((IOTA - 30) & 63)] + (fVec0[((IOTA - 22) & 63)] + (fVec0[((IOTA - 6) & 63)] + fVec0[((IOTA - 14) & 63)])))))));
			float fTemp301 = (0.707106769f * fTemp296);
			float fTemp302 = (fVec0[((IOTA - 58) & 63)] + (fVec0[((IOTA - 50) & 63)] + (fVec0[((IOTA - 42) & 63)] + (fVec0[((IOTA - 34) & 63)] + (fVec0[((IOTA - 26) & 63)] + (fVec0[((IOTA - 18) & 63)] + (fVec0[((IOTA - 2) & 63)] + fVec0[((IOTA - 10) & 63)])))))));
			output8[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.707106769f * fTemp295) + (fTemp297 + fTemp298)) - fTemp299))) + mydsp_faustpower2_f(std::fabs((((0.707106769f * fTemp295) + fTemp300) - (fTemp301 + fTemp302))))));
			float fTemp303 = ((fTemp17 + (0.382683426f * fTemp7)) - (fTemp18 + (fVec0[((IOTA - 19) & 63)] + (0.923879504f * fTemp11))));
			float fTemp304 = (0.980785251f * fTemp303);
			float fTemp305 = (fTemp26 + fTemp31);
			float fTemp306 = ((fTemp9 + fTemp14) - ((0.923879504f * fTemp7) + (fVec0[((IOTA - 35) & 63)] + (0.382683426f * fTemp11))));
			float fTemp307 = ((0.923879504f * fTemp24) + (fVec0[((IOTA - 33) & 63)] + (0.382683426f * fTemp28)));
			float fTemp308 = ((fTemp304 + fTemp305) - ((0.195090324f * fTemp306) + fTemp307));
			float fTemp309 = ((0.382683426f * fTemp24) + fTemp35);
			float fTemp310 = (0.980785251f * fTemp306);
			float fTemp311 = (fTemp37 + (fVec0[((IOTA - 17) & 63)] + (0.923879504f * fTemp28)));
			float fTemp312 = (fTemp309 - (fTemp310 + (fTemp311 + (0.195090324f * fTemp303))));
			float fTemp313 = (((0.382683426f * fTemp44) + fTemp54) - (fTemp55 + (fVec0[((IOTA - 18) & 63)] + (0.923879504f * fTemp48))));
			float fTemp314 = (0.980785251f * fTemp313);
			float fTemp315 = ((fTemp46 + fTemp51) - ((0.923879504f * fTemp44) + (fVec0[((IOTA - 34) & 63)] + (0.382683426f * fTemp48))));
			float fTemp316 = ((0.923879504f * fTemp61) + (fVec0[((IOTA - 32) & 63)] + (0.382683426f * fTemp63)));
			float fTemp317 = ((0.382683426f * fTemp61) + fTemp71);
			float fTemp318 = (0.980785251f * fTemp315);
			float fTemp319 = ((0.923879504f * fTemp63) + fTemp74);
			output9[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.634393275f * fTemp308) + ((0.773010433f * fTemp312) + (fTemp68 + fTemp314))) - ((0.195090324f * fTemp315) + fTemp316)))) + mydsp_faustpower2_f(std::fabs((((0.634393275f * fTemp312) + fTemp317) - (fTemp318 + ((0.773010433f * fTemp308) + ((0.195090324f * fTemp313) + fTemp319))))))));
			float fTemp320 = ((fTemp87 + fTemp89) - (fTemp88 + (0.707106769f * fTemp81)));
			float fTemp321 = (0.707106769f * fTemp76);
			float fTemp322 = (fTemp78 - (fTemp321 + (fTemp82 + fTemp83)));
			float fTemp323 = (0.707106769f * fTemp85);
			float fTemp324 = (fTemp323 + (fTemp94 + fTemp97));
			float fTemp325 = ((fTemp95 + (0.923879504f * fTemp320)) - ((0.382683426f * fTemp322) + fTemp324));
			float fTemp326 = (fTemp99 + fTemp101);
			float fTemp327 = (fTemp102 + (0.707106769f * fTemp93));
			float fTemp328 = (fTemp326 - ((0.923879504f * fTemp322) + ((0.382683426f * fTemp320) + fTemp327)));
			float fTemp329 = ((fTemp113 + fTemp114) - (fTemp115 + (0.707106769f * fTemp108)));
			float fTemp330 = (0.707106769f * fTemp104);
			float fTemp331 = (fTemp110 - (fTemp330 + (fTemp109 + fTemp111)));
			float fTemp332 = (0.707106769f * fTemp122);
			float fTemp333 = (fTemp120 + (fTemp125 + fTemp332));
			float fTemp334 = (fTemp126 + fTemp128);
			float fTemp335 = (fTemp129 + (0.707106769f * fTemp119));
			output10[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.555570245f * fTemp325) + ((0.831469595f * fTemp328) + (fTemp121 + (0.923879504f * fTemp329)))) - ((0.382683426f * fTemp331) + fTemp333)))) + mydsp_faustpower2_f(std::fabs((((0.555570245f * fTemp328) + fTemp334) - ((0.923879504f * fTemp331) + ((0.831469595f * fTemp325) + ((0.382683426f * fTemp329) + fTemp335))))))));
			float fTemp336 = ((fVec0[((IOTA - 19) & 63)] + (0.923879504f * fTemp132)) - (fTemp146 + (fTemp145 + (0.382683426f * fTemp135))));
			float fTemp337 = (0.831469595f * fTemp336);
			float fTemp338 = (fVec0[((IOTA - 1) & 63)] + fTemp144);
			float fTemp339 = ((fVec0[((IOTA - 3) & 63)] + fTemp134) - ((0.382683426f * fTemp132) + (fTemp136 + (0.923879504f * fTemp135))));
			float fTemp340 = ((0.923879504f * fTemp139) + (fTemp148 + (0.382683426f * fTemp141)));
			float fTemp341 = ((fTemp337 + fTemp338) - ((0.555570245f * fTemp339) + fTemp340));
			float fTemp342 = (fVec0[((IOTA - 17) & 63)] + (0.923879504f * fTemp141));
			float fTemp343 = (0.831469595f * fTemp339);
			float fTemp344 = (fTemp154 + (0.382683426f * fTemp139));
			float fTemp345 = (fTemp342 - (fTemp343 + ((0.555570245f * fTemp336) + fTemp344)));
			float fTemp346 = ((fVec0[((IOTA - 18) & 63)] + (0.923879504f * fTemp158)) - (fTemp163 + (0.382683426f * fTemp157)));
			float fTemp347 = (0.831469595f * fTemp346);
			float fTemp348 = (fTemp160 - ((0.923879504f * fTemp157) + (fTemp161 + (0.382683426f * fTemp158))));
			float fTemp349 = ((0.923879504f * fTemp166) + (fTemp171 + (0.382683426f * fTemp167)));
			float fTemp350 = (fVec0[((IOTA - 16) & 63)] + (0.923879504f * fTemp167));
			float fTemp351 = (0.831469595f * fTemp348);
			float fTemp352 = (fTemp173 + (0.382683426f * fTemp166));
			output11[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.471396744f * fTemp341) + ((0.881921291f * fTemp345) + (fTemp169 + fTemp347))) - ((0.555570245f * fTemp348) + fTemp349)))) + mydsp_faustpower2_f(std::fabs((((0.471396744f * fTemp345) + fTemp350) - (fTemp351 + ((0.881921291f * fTemp341) + ((0.555570245f * fTemp346) + fTemp352))))))));
			float fTemp353 = (fTemp178 - fTemp177);
			float fTemp354 = ((fTemp181 + (0.707106769f * fTemp353)) - (fTemp185 + fTemp182));
			float fTemp355 = (fTemp186 - ((0.707106769f * fTemp353) + (fTemp184 + fTemp176)));
			float fTemp356 = (fTemp189 - fTemp188);
			output12[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.382683426f * fTemp354) + ((0.923879504f * fTemp355) + (fTemp194 + (0.707106769f * fTemp356)))) - (fTemp195 + fTemp197)))) + mydsp_faustpower2_f(std::fabs(((fTemp198 + (0.382683426f * fTemp355)) - ((0.923879504f * fTemp354) + ((0.707106769f * fTemp356) + (fTemp193 + fTemp196))))))));
			float fTemp357 = (((0.923879504f * fTemp203) + (fTemp207 + (0.382683426f * fTemp199))) - fTemp208);
			float fTemp358 = (0.555570245f * fTemp357);
			float fTemp359 = (fVec0[((IOTA - 1) & 63)] + (0.382683426f * fTemp212));
			float fTemp360 = ((fVec0[((IOTA - 3) & 63)] + (0.382683426f * fTemp203)) - ((0.923879504f * fTemp199) + fTemp201));
			float fTemp361 = ((0.923879504f * fTemp205) + fTemp214);
			float fTemp362 = ((fTemp358 + fTemp359) - ((0.831469595f * fTemp360) + fTemp361));
			float fTemp363 = ((0.923879504f * fTemp212) + ((0.382683426f * fTemp205) + fTemp217));
			float fTemp364 = (0.555570245f * fTemp360);
			float fTemp365 = (fTemp363 - (fTemp364 + (fTemp219 + (0.831469595f * fTemp357))));
			float fTemp366 = (((0.923879504f * fTemp224) + (fTemp228 + (0.382683426f * fTemp222))) - fTemp229);
			float fTemp367 = (0.555570245f * fTemp366);
			float fTemp368 = (fTemp2 + (0.382683426f * fTemp235));
			float fTemp369 = ((fVec0[((IOTA - 2) & 63)] + (0.382683426f * fTemp224)) - ((0.923879504f * fTemp222) + fTemp226));
			float fTemp370 = ((0.923879504f * fTemp232) + fTemp237);
			float fTemp371 = ((0.923879504f * fTemp235) + ((0.382683426f * fTemp232) + fTemp239));
			float fTemp372 = (0.555570245f * fTemp369);
			output13[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.290284663f * fTemp362) + ((0.956940353f * fTemp365) + (fTemp367 + fTemp368))) - ((0.831469595f * fTemp369) + fTemp370)))) + mydsp_faustpower2_f(std::fabs((((0.290284663f * fTemp365) + fTemp371) - (fTemp372 + ((0.956940353f * fTemp362) + (fTemp241 + (0.831469595f * fTemp366)))))))));
			float fTemp373 = (((fTemp88 + fTemp321) + (0.707106769f * fTemp243)) - fTemp87);
			float fTemp374 = (fTemp95 + (0.707106769f * fTemp85));
			float fTemp375 = ((fTemp78 + (0.707106769f * fTemp76)) - (fTemp83 + (0.707106769f * fTemp243)));
			float fTemp376 = (fTemp97 + (0.707106769f * fTemp245));
			float fTemp377 = (((0.382683426f * fTemp373) + fTemp374) - ((0.923879504f * fTemp375) + fTemp376));
			float fTemp378 = ((0.707106769f * fTemp245) + (fTemp102 + fTemp323));
			float fTemp379 = (fTemp378 - ((0.382683426f * fTemp375) + (fTemp99 + (0.923879504f * fTemp373))));
			float fTemp380 = (((0.707106769f * fTemp253) + (fTemp115 + fTemp330)) - fTemp113);
			float fTemp381 = (fTemp121 + (0.707106769f * fTemp122));
			float fTemp382 = ((fTemp110 + (0.707106769f * fTemp104)) - (fTemp111 + (0.707106769f * fTemp253)));
			float fTemp383 = (fTemp125 + (0.707106769f * fTemp256));
			float fTemp384 = ((0.707106769f * fTemp256) + (fTemp129 + fTemp332));
			output14[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.195090324f * fTemp377) + ((0.980785251f * fTemp379) + ((0.382683426f * fTemp380) + fTemp381))) - ((0.923879504f * fTemp382) + fTemp383)))) + mydsp_faustpower2_f(std::fabs((((0.195090324f * fTemp379) + fTemp384) - ((0.382683426f * fTemp382) + ((0.980785251f * fTemp377) + (fTemp126 + (0.923879504f * fTemp380)))))))));
			float fTemp385 = (((fTemp267 + (0.382683426f * fTemp265)) + (0.923879504f * fTemp263)) - fVec0[((IOTA - 51) & 63)]);
			float fTemp386 = ((0.923879504f * fTemp270) + fTemp269);
			float fTemp387 = (0.382683426f * fTemp260);
			float fTemp388 = ((fTemp262 + (0.923879504f * fTemp265)) - (fTemp264 + (0.382683426f * fTemp263)));
			float fTemp389 = (((0.195090324f * fTemp385) + fTemp386) - (fTemp387 + ((0.980785251f * fTemp388) + fTemp272)));
			float fTemp390 = (0.923879504f * fTemp260);
			float fTemp391 = ((0.382683426f * fTemp270) + fTemp274);
			float fTemp392 = ((fTemp390 + fTemp391) - ((0.195090324f * fTemp388) + (fVec0[((IOTA - 49) & 63)] + (0.980785251f * fTemp385))));
			float fTemp393 = (((0.923879504f * fTemp278) + ((0.382683426f * fTemp280) + fTemp283)) - fVec0[((IOTA - 50) & 63)]);
			float fTemp394 = ((0.923879504f * fTemp288) + fTemp286);
			float fTemp395 = (((0.923879504f * fTemp280) + fTemp279) - (fTemp281 + (0.382683426f * fTemp278)));
			float fTemp396 = (fTemp289 + (0.382683426f * fTemp285));
			float fTemp397 = ((0.923879504f * fTemp285) + ((0.382683426f * fTemp288) + fTemp291));
			output15[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.0980171412f * fTemp389) + ((0.99518472f * fTemp392) + ((0.195090324f * fTemp393) + fTemp394))) - ((0.980785251f * fTemp395) + fTemp396)))) + mydsp_faustpower2_f(std::fabs((((0.0980171412f * fTemp392) + fTemp397) - ((0.195090324f * fTemp395) + ((0.99518472f * fTemp389) + (fVec0[((IOTA - 48) & 63)] + (0.980785251f * fTemp393)))))))));
			output16[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fVec0[((IOTA - 60) & 63)] + (fVec0[((IOTA - 56) & 63)] + (fVec0[((IOTA - 52) & 63)] + (fVec0[((IOTA - 48) & 63)] + (fVec0[((IOTA - 44) & 63)] + (fVec0[((IOTA - 40) & 63)] + (fVec0[((IOTA - 36) & 63)] + (fVec0[((IOTA - 32) & 63)] + (fVec0[((IOTA - 28) & 63)] + (fVec0[((IOTA - 24) & 63)] + (fVec0[((IOTA - 20) & 63)] + (fVec0[((IOTA - 16) & 63)] + (fVec0[((IOTA - 12) & 63)] + (fVec0[((IOTA - 8) & 63)] + (fTemp2 + fVec0[((IOTA - 4) & 63)]))))))))))))))) - (fVec0[((IOTA - 62) & 63)] + (fVec0[((IOTA - 58) & 63)] + (fVec0[((IOTA - 54) & 63)] + (fVec0[((IOTA - 50) & 63)] + (fVec0[((IOTA - 46) & 63)] + (fVec0[((IOTA - 42) & 63)] + (fVec0[((IOTA - 38) & 63)] + (fVec0[((IOTA - 34) & 63)] + (fVec0[((IOTA - 30) & 63)] + (fVec0[((IOTA - 26) & 63)] + (fVec0[((IOTA - 22) & 63)] + (fVec0[((IOTA - 18) & 63)] + (fVec0[((IOTA - 14) & 63)] + (fVec0[((IOTA - 10) & 63)] + (fVec0[((IOTA - 2) & 63)] + fVec0[((IOTA - 6) & 63)])))))))))))))))))) + mydsp_faustpower2_f(std::fabs(((fVec0[((IOTA - 63) & 63)] + (fVec0[((IOTA - 59) & 63)] + (fVec0[((IOTA - 55) & 63)] + (fVec0[((IOTA - 51) & 63)] + (fVec0[((IOTA - 47) & 63)] + (fVec0[((IOTA - 43) & 63)] + (fVec0[((IOTA - 39) & 63)] + (fVec0[((IOTA - 35) & 63)] + (fVec0[((IOTA - 31) & 63)] + (fVec0[((IOTA - 27) & 63)] + (fVec0[((IOTA - 23) & 63)] + (fVec0[((IOTA - 19) & 63)] + (fVec0[((IOTA - 15) & 63)] + (fVec0[((IOTA - 11) & 63)] + (fVec0[((IOTA - 3) & 63)] + fVec0[((IOTA - 7) & 63)]))))))))))))))) - (fVec0[((IOTA - 61) & 63)] + (fVec0[((IOTA - 57) & 63)] + (fVec0[((IOTA - 53) & 63)] + (fVec0[((IOTA - 49) & 63)] + (fVec0[((IOTA - 45) & 63)] + (fVec0[((IOTA - 41) & 63)] + (fVec0[((IOTA - 37) & 63)] + (fVec0[((IOTA - 33) & 63)] + (fVec0[((IOTA - 29) & 63)] + (fVec0[((IOTA - 25) & 63)] + (fVec0[((IOTA - 21) & 63)] + (fVec0[((IOTA - 17) & 63)] + (fVec0[((IOTA - 13) & 63)] + (fVec0[((IOTA - 9) & 63)] + (fVec0[((IOTA - 1) & 63)] + fVec0[((IOTA - 5) & 63)]))))))))))))))))))));
			float fTemp398 = ((fTemp36 + (0.195090324f * fTemp15)) - (fTemp34 + fTemp38));
			float fTemp399 = (fTemp32 - (fTemp16 + (fVec0[((IOTA - 33) & 63)] + (0.195090324f * fTemp19))));
			output17[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp69 + (0.99518472f * fTemp398)) - ((0.0980171412f * fTemp399) + (fTemp53 + (fVec0[((IOTA - 32) & 63)] + (0.195090324f * fTemp56))))))) + mydsp_faustpower2_f(std::fabs(((fTemp72 + (0.195090324f * fTemp52)) - ((0.99518472f * fTemp399) + ((0.0980171412f * fTemp398) + (fTemp70 + fTemp75))))))));
			float fTemp400 = ((fTemp100 + (0.382683426f * fTemp84)) - (fTemp101 + (fTemp102 + (0.923879504f * fTemp90))));
			float fTemp401 = ((fTemp86 + fTemp96) - ((0.923879504f * fTemp84) + (fTemp97 + (0.382683426f * fTemp90))));
			output18[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp124 + (0.980785251f * fTemp400)) - ((0.195090324f * fTemp401) + ((0.923879504f * fTemp112) + (fTemp125 + (0.382683426f * fTemp116))))))) + mydsp_faustpower2_f(std::fabs(((fTemp127 + (0.382683426f * fTemp112)) - ((0.980785251f * fTemp401) + ((0.195090324f * fTemp400) + (fTemp130 + (0.923879504f * fTemp116)))))))));
			float fTemp402 = (((0.555570245f * fTemp137) + (fVec0[((IOTA - 17) & 63)] + fTemp150)) - (fTemp151 + (fTemp152 + ((0.831469595f * fTemp147) + fTemp153))));
			float fTemp403 = ((fTemp140 + (fTemp142 + fTemp338)) - ((0.831469595f * fTemp137) + (fTemp148 + (0.555570245f * fTemp147))));
			output19[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp170 + (0.956940353f * fTemp402)) - ((0.290284663f * fTemp403) + ((0.831469595f * fTemp162) + (fTemp171 + (0.555570245f * fTemp164))))))) + mydsp_faustpower2_f(std::fabs(((fTemp172 + (0.555570245f * fTemp162)) - ((0.956940353f * fTemp403) + ((0.290284663f * fTemp402) + (fTemp174 + (0.831469595f * fTemp164)))))))));
			float fTemp404 = ((fTemp184 + fTemp185) - (fTemp186 + (0.707106769f * fTemp179)));
			float fTemp405 = (0.707106769f * fTemp175);
			float fTemp406 = (fTemp181 - (fTemp405 + (fTemp180 + fTemp182)));
			float fTemp407 = (0.707106769f * fTemp192);
			output20[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp194 + (0.923879504f * fTemp404)) - ((0.382683426f * fTemp406) + (fTemp191 + (fTemp195 + fTemp407)))))) + mydsp_faustpower2_f(std::fabs(((fTemp196 + fTemp197) - ((0.923879504f * fTemp406) + ((0.382683426f * fTemp404) + (fTemp198 + (0.707106769f * fTemp190)))))))));
			float fTemp408 = ((fTemp217 + fTemp218) - (fTemp220 + (0.555570245f * fTemp209)));
			float fTemp409 = (fTemp206 - ((0.555570245f * fTemp204) + (fTemp210 + fTemp215)));
			output21[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp233 + (0.881921291f * fTemp408)) - ((0.471396744f * fTemp409) + ((0.555570245f * fTemp227) + (fTemp231 + fTemp238)))))) + mydsp_faustpower2_f(std::fabs(((fTemp239 + fTemp240) - ((0.881921291f * fTemp409) + ((0.471396744f * fTemp408) + (fTemp242 + (0.555570245f * fTemp230)))))))));
			float fTemp410 = ((fTemp102 + (0.923879504f * fTemp244)) - (fTemp250 + (fTemp251 + (0.382683426f * fTemp247))));
			float fTemp411 = ((fTemp95 + fTemp246) - ((0.382683426f * fTemp244) + (fTemp248 + (0.923879504f * fTemp247))));
			output22[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp257 + (0.831469595f * fTemp410)) - ((0.555570245f * fTemp411) + ((0.382683426f * fTemp254) + (fTemp258 + (0.923879504f * fTemp255))))))) + mydsp_faustpower2_f(std::fabs(((fTemp129 + (0.923879504f * fTemp254)) - ((0.831469595f * fTemp411) + ((0.555570245f * fTemp410) + (fTemp259 + (0.382683426f * fTemp255)))))))));
			float fTemp412 = (((0.980785251f * fTemp266) + fTemp274) - ((fTemp276 + (fVec0[((IOTA - 49) & 63)] + (0.195090324f * fTemp268))) + fTemp275));
			float fTemp413 = ((fTemp261 + fTemp269) - ((0.195090324f * fTemp266) + (fTemp271 + ((0.980785251f * fTemp268) + fTemp272))));
			output23[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp287 + (0.773010433f * fTemp412)) - ((0.634393275f * fTemp413) + ((0.195090324f * fTemp282) + (fTemp290 + (0.980785251f * fTemp284))))))) + mydsp_faustpower2_f(std::fabs(((fTemp291 + (0.980785251f * fTemp282)) - ((0.773010433f * fTemp413) + ((0.634393275f * fTemp412) + (fTemp292 + (0.195090324f * fTemp284)))))))));
			float fTemp414 = (fTemp294 - fTemp293);
			output24[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp298 + (0.707106769f * fTemp414)) - (fTemp299 + fTemp301)))) + mydsp_faustpower2_f(std::fabs((fTemp302 - ((0.707106769f * fTemp414) + (fTemp297 + fTemp300)))))));
			float fTemp415 = ((fTemp310 + (fTemp309 + (0.195090324f * fTemp303))) - fTemp311);
			float fTemp416 = ((fTemp305 + (0.195090324f * fTemp306)) - (fTemp304 + fTemp307));
			output25[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.634393275f * fTemp415) + (fTemp68 + (0.195090324f * fTemp315))) - ((0.773010433f * fTemp416) + (fTemp314 + fTemp316))))) + mydsp_faustpower2_f(std::fabs(((fTemp318 + (fTemp317 + (0.195090324f * fTemp313))) - ((0.634393275f * fTemp416) + (fTemp319 + (0.773010433f * fTemp415))))))));
			float fTemp417 = (((0.923879504f * fTemp322) + (fTemp326 + (0.382683426f * fTemp320))) - fTemp327);
			float fTemp418 = ((fTemp95 + (0.382683426f * fTemp322)) - (fTemp324 + (0.923879504f * fTemp320)));
			output26[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.555570245f * fTemp417) + (fTemp121 + (0.382683426f * fTemp331))) - ((0.831469595f * fTemp418) + (fTemp333 + (0.923879504f * fTemp329)))))) + mydsp_faustpower2_f(std::fabs((((0.923879504f * fTemp331) + (fTemp334 + (0.382683426f * fTemp329))) - ((0.555570245f * fTemp418) + (fTemp335 + (0.831469595f * fTemp417))))))));
			float fTemp419 = ((fTemp343 + (fTemp342 + (0.555570245f * fTemp336))) - fTemp344);
			float fTemp420 = ((fTemp338 + (0.555570245f * fTemp339)) - (fTemp337 + fTemp340));
			output27[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.471396744f * fTemp419) + (fTemp169 + (0.555570245f * fTemp348))) - ((0.881921291f * fTemp420) + (fTemp347 + fTemp349))))) + mydsp_faustpower2_f(std::fabs(((fTemp351 + (fTemp350 + (0.555570245f * fTemp346))) - ((0.471396744f * fTemp420) + (fTemp352 + (0.881921291f * fTemp419))))))));
			float fTemp421 = (((0.707106769f * fTemp353) + (fTemp186 + fTemp405)) - fTemp184);
			float fTemp422 = ((fTemp181 + (0.707106769f * fTemp175)) - (fTemp182 + (0.707106769f * fTemp353)));
			output28[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.382683426f * fTemp421) + (fTemp194 + (0.707106769f * fTemp192))) - ((0.923879504f * fTemp422) + (fTemp195 + (0.707106769f * fTemp356)))))) + mydsp_faustpower2_f(std::fabs((((0.707106769f * fTemp356) + (fTemp198 + fTemp407)) - ((0.382683426f * fTemp422) + (fTemp196 + (0.923879504f * fTemp421))))))));
			float fTemp423 = ((fTemp364 + (fTemp363 + (0.831469595f * fTemp357))) - fTemp219);
			float fTemp424 = ((fTemp359 + (0.831469595f * fTemp360)) - (fTemp358 + fTemp361));
			output29[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.290284663f * fTemp423) + (fTemp368 + (0.831469595f * fTemp369))) - ((0.956940353f * fTemp424) + (fTemp367 + fTemp370))))) + mydsp_faustpower2_f(std::fabs(((fTemp372 + (fTemp371 + (0.831469595f * fTemp366))) - ((0.290284663f * fTemp424) + (fTemp241 + (0.956940353f * fTemp423))))))));
			float fTemp425 = (((0.382683426f * fTemp375) + (fTemp378 + (0.923879504f * fTemp373))) - fTemp99);
			float fTemp426 = ((fTemp374 + (0.923879504f * fTemp375)) - (fTemp376 + (0.382683426f * fTemp373)));
			output30[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.195090324f * fTemp425) + (fTemp381 + (0.923879504f * fTemp382))) - ((0.980785251f * fTemp426) + (fTemp383 + (0.382683426f * fTemp380)))))) + mydsp_faustpower2_f(std::fabs((((0.382683426f * fTemp382) + (fTemp384 + (0.923879504f * fTemp380))) - ((0.195090324f * fTemp426) + (fTemp126 + (0.980785251f * fTemp425))))))));
			float fTemp427 = ((fTemp390 + ((0.195090324f * fTemp388) + ((0.980785251f * fTemp385) + fTemp391))) - fVec0[((IOTA - 49) & 63)]);
			float fTemp428 = (((0.980785251f * fTemp388) + fTemp386) - (fTemp387 + ((0.195090324f * fTemp385) + fTemp272)));
			output31[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.0980171412f * fTemp427) + (fTemp394 + (0.980785251f * fTemp395))) - ((0.99518472f * fTemp428) + (fTemp396 + (0.195090324f * fTemp393)))))) + mydsp_faustpower2_f(std::fabs((((0.195090324f * fTemp395) + (fTemp397 + (0.980785251f * fTemp393))) - ((0.0980171412f * fTemp428) + (fVec0[((IOTA - 48) & 63)] + (0.99518472f * fTemp427))))))));
			output32[i] = FAUSTFLOAT(mydsp_faustpower2_f(std::fabs(((fVec0[((IOTA - 62) & 63)] + (fVec0[((IOTA - 60) & 63)] + (fVec0[((IOTA - 58) & 63)] + (fVec0[((IOTA - 56) & 63)] + (fVec0[((IOTA - 54) & 63)] + (fVec0[((IOTA - 52) & 63)] + (fVec0[((IOTA - 50) & 63)] + (fVec0[((IOTA - 48) & 63)] + (fVec0[((IOTA - 46) & 63)] + (fVec0[((IOTA - 44) & 63)] + (fVec0[((IOTA - 42) & 63)] + (fVec0[((IOTA - 40) & 63)] + (fVec0[((IOTA - 38) & 63)] + (fVec0[((IOTA - 36) & 63)] + (fVec0[((IOTA - 34) & 63)] + (fVec0[((IOTA - 32) & 63)] + (fVec0[((IOTA - 30) & 63)] + (fVec0[((IOTA - 28) & 63)] + (fVec0[((IOTA - 26) & 63)] + (fVec0[((IOTA - 24) & 63)] + (fVec0[((IOTA - 22) & 63)] + (fVec0[((IOTA - 20) & 63)] + (fVec0[((IOTA - 18) & 63)] + (fVec0[((IOTA - 16) & 63)] + (fVec0[((IOTA - 14) & 63)] + (fVec0[((IOTA - 12) & 63)] + (fVec0[((IOTA - 10) & 63)] + (fVec0[((IOTA - 8) & 63)] + (fVec0[((IOTA - 6) & 63)] + (fVec0[((IOTA - 4) & 63)] + (fTemp2 + fVec0[((IOTA - 2) & 63)]))))))))))))))))))))))))))))))) - (fVec0[((IOTA - 63) & 63)] + (fVec0[((IOTA - 61) & 63)] + (fVec0[((IOTA - 59) & 63)] + (fVec0[((IOTA - 57) & 63)] + (fVec0[((IOTA - 55) & 63)] + (fVec0[((IOTA - 53) & 63)] + (fVec0[((IOTA - 51) & 63)] + (fVec0[((IOTA - 49) & 63)] + (fVec0[((IOTA - 47) & 63)] + (fVec0[((IOTA - 45) & 63)] + (fVec0[((IOTA - 43) & 63)] + (fVec0[((IOTA - 41) & 63)] + (fVec0[((IOTA - 39) & 63)] + (fVec0[((IOTA - 37) & 63)] + (fVec0[((IOTA - 35) & 63)] + (fVec0[((IOTA - 33) & 63)] + (fVec0[((IOTA - 31) & 63)] + (fVec0[((IOTA - 29) & 63)] + (fVec0[((IOTA - 27) & 63)] + (fVec0[((IOTA - 25) & 63)] + (fVec0[((IOTA - 23) & 63)] + (fVec0[((IOTA - 21) & 63)] + (fVec0[((IOTA - 19) & 63)] + (fVec0[((IOTA - 17) & 63)] + (fVec0[((IOTA - 15) & 63)] + (fVec0[((IOTA - 13) & 63)] + (fVec0[((IOTA - 11) & 63)] + (fVec0[((IOTA - 9) & 63)] + (fVec0[((IOTA - 7) & 63)] + (fVec0[((IOTA - 5) & 63)] + (fVec0[((IOTA - 1) & 63)] + fVec0[((IOTA - 3) & 63)])))))))))))))))))))))))))))))))))));
			fRec1[1] = fRec1[0];
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
