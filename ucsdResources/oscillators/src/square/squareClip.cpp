/* ------------------------------------------------------------
name: "squareClip"
Code generated with Faust 2.7.0 (https://faust.grame.fr)
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
	
	float fRec0[2];
	float fVec0[16];
	int fSamplingFreq;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("filename", "squareClip");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "squareClip");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
	}

	virtual int getNumInputs() {
		return 0;
		
	}
	virtual int getNumOutputs() {
		return 9;
		
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
		for (int l1 = 0; (l1 < 16); l1 = (l1 + 1)) {
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
		ui_interface->openVerticalBox("squareClip");
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
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec0[0] = std::fmod((fRec0[1] + 0.0125000002f), 1.0f);
			float fTemp0 = std::max(-1.0f, std::min(1.0f, (9999999.0f * ((2.0f * fRec0[0]) + -1.0f))));
			fVec0[0] = fTemp0;
			float fTemp1 = (fTemp0 + fVec0[8]);
			float fTemp2 = (fVec0[12] + (fTemp1 + fVec0[4]));
			float fTemp3 = (fVec0[14] + (fVec0[6] + (fVec0[10] + (fTemp2 + fVec0[2]))));
			output0[i] = FAUSTFLOAT(mydsp_faustpower2_f(std::fabs((fVec0[15] + (fVec0[7] + (fVec0[11] + (fVec0[3] + (fVec0[13] + (fVec0[5] + (fVec0[9] + (fTemp3 + fVec0[1])))))))))));
			float fTemp4 = (fVec0[7] - fVec0[15]);
			float fTemp5 = (0.0f - fTemp4);
			float fTemp6 = (fVec0[3] - fVec0[11]);
			float fTemp7 = (0.707106769f * fTemp6);
			float fTemp8 = ((fVec0[13] + (0.707106769f * fTemp5)) - (fVec0[5] + fTemp7));
			float fTemp9 = (fVec0[6] - fVec0[14]);
			float fTemp10 = (0.0f - fTemp9);
			float fTemp11 = (0.707106769f * fTemp10);
			float fTemp12 = (fVec0[2] - fVec0[10]);
			float fTemp13 = (0.707106769f * fTemp12);
			float fTemp14 = (0.707106769f * fTemp5);
			float fTemp15 = (0.707106769f * fTemp6);
			float fTemp16 = ((fTemp14 + (fVec0[1] + fTemp15)) - fVec0[9]);
			float fTemp17 = (0.707106769f * fTemp12);
			output1[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.382683426f * fTemp8) + ((fTemp11 + (fTemp0 + fTemp13)) + (0.923879504f * fTemp16))) - fVec0[8]))) + mydsp_faustpower2_f(std::fabs((((fVec0[12] + (0.707106769f * fTemp10)) + (0.923879504f * fTemp8)) - ((fVec0[4] + fTemp17) + (0.382683426f * fTemp16)))))));
			float fTemp18 = (fVec0[3] + fVec0[11]);
			float fTemp19 = (fTemp18 - (fVec0[7] + fVec0[15]));
			float fTemp20 = (0.0f - fTemp19);
			float fTemp21 = (fVec0[1] + fVec0[9]);
			float fTemp22 = (fTemp21 - (fVec0[5] + fVec0[13]));
			float fTemp23 = (0.707106769f * fTemp22);
			float fTemp24 = (fVec0[4] + fVec0[12]);
			float fTemp25 = (fVec0[6] + fVec0[14]);
			float fTemp26 = (fVec0[2] + fVec0[10]);
			float fTemp27 = (0.707106769f * fTemp22);
			output2[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.707106769f * fTemp20) + (fTemp1 + fTemp23)) - fTemp24))) + mydsp_faustpower2_f(std::fabs(((fTemp25 + (0.707106769f * fTemp20)) - (fTemp26 + fTemp27))))));
			float fTemp28 = (fVec0[5] - ((0.707106769f * fTemp4) + (fVec0[13] + fTemp15)));
			float fTemp29 = ((fVec0[1] + (0.707106769f * fTemp4)) - (fVec0[9] + fTemp7));
			output3[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((0.923879504f * fTemp28) + ((fTemp0 + (0.707106769f * fTemp9)) + (0.382683426f * fTemp29))) - (fVec0[8] + fTemp17)))) + mydsp_faustpower2_f(std::fabs(((fVec0[4] + (0.382683426f * fTemp28)) - (((0.707106769f * fTemp9) + (fVec0[12] + fTemp13)) + (0.923879504f * fTemp29)))))));
			float fTemp30 = (fVec0[13] + (fTemp21 + fVec0[5]));
			output4[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((fTemp2 - (fVec0[14] + (fTemp26 + fVec0[6]))))) + mydsp_faustpower2_f(std::fabs((0.0f - (fTemp30 - (fVec0[15] + (fTemp18 + fVec0[7]))))))));
			float fTemp31 = ((fVec0[13] + fTemp7) - (fVec0[5] + (0.707106769f * fTemp5)));
			float fTemp32 = (0.707106769f * fTemp12);
			float fTemp33 = (0.707106769f * fTemp6);
			float fTemp34 = (fVec0[1] - (fTemp14 + (fVec0[9] + fTemp33)));
			output5[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp0 + (0.923879504f * fTemp31)) - ((fTemp11 + (fVec0[8] + fTemp32)) + (0.382683426f * fTemp34))))) + mydsp_faustpower2_f(std::fabs(((fVec0[12] + fTemp17) - ((0.382683426f * fTemp31) + ((fVec0[4] + (0.707106769f * fTemp10)) + (0.923879504f * fTemp34))))))));
			output6[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs(((fTemp1 + (0.707106769f * fTemp19)) - (fTemp24 + fTemp27)))) + mydsp_faustpower2_f(std::fabs((fTemp26 - ((0.707106769f * fTemp19) + (fTemp25 + fTemp23)))))));
			float fTemp35 = (((0.707106769f * fTemp4) + (fVec0[5] + fTemp33)) - fVec0[13]);
			float fTemp36 = ((fVec0[1] + (0.707106769f * fTemp6)) - (fVec0[9] + (0.707106769f * fTemp4)));
			output7[i] = FAUSTFLOAT((mydsp_faustpower2_f(std::fabs((((fTemp0 + (0.707106769f * fTemp12)) + (0.382683426f * fTemp35)) - ((fVec0[8] + (0.707106769f * fTemp9)) + (0.923879504f * fTemp36))))) + mydsp_faustpower2_f(std::fabs((((0.707106769f * fTemp9) + (fVec0[4] + fTemp32)) - ((0.923879504f * fTemp35) + (fVec0[12] + (0.382683426f * fTemp36))))))));
			output8[i] = FAUSTFLOAT(mydsp_faustpower2_f(std::fabs((fTemp3 - (fVec0[15] + (fVec0[7] + (fVec0[11] + (fTemp30 + fVec0[3]))))))));
			fRec0[1] = fRec0[0];
			for (int j0 = 15; (j0 > 0); j0 = (j0 - 1)) {
				fVec0[j0] = fVec0[(j0 - 1)];
				
			}
			
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
