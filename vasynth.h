#pragma once
#ifndef DSY_VAVOICE_H
#define DSY_VAVOICE_H

#include "daisysp.h"

#include "main.h"

// preset
#define PRESET_MAX 10

using namespace daisy;
using namespace daisysp;
//using namespace infrasonic;

typedef struct
{
	// config
	uint8_t waveform;
	float osc_mix;
	float detune;
	
	float filter_res;
	float filter_cutoff;
	float eg_f_amount;
	float osc_pw;
	
	float eg_a_attack;
	float eg_a_decay;
	float eg_a_sustain; // level
	float eg_a_release;
	float eg_f_attack;
	float eg_f_decay;
	float eg_f_sustain; // level
	float eg_f_release;
	
	uint8_t lfo_waveform;
	float lfo_freq;
	float lfo_amp;

	uint8_t pwmlfo_waveform;
	float pwmlfo_freq;
	float pwmlfo_amp;

	uint8_t vcflfo_waveform;
	float vcflfo_freq;
	float vcflfo_amp;
	
	uint8_t vcalfo_waveform;
	float vcalfo_freq;
	float vcalfo_amp;

	uint8_t osc2_waveform;
	float osc2_detune;
	float osc2_transpose;
	uint8_t vel_select;
	
	uint8_t midi_channel;
	float osc2_pw;
} VASynthSetting;

class VASynth
{
	public:

    VASynth() {}
    ~VASynth() {}

    enum Waveform
    {
        WAVE_SIN,
        WAVE_TRI,
        WAVE_SAW,
        WAVE_RAMP,
        WAVE_SQUARE,
        WAVE_POLYBLEP_TRI,
        WAVE_POLYBLEP_SAW,
        WAVE_POLYBLEP_SQUARE,
        WAVE_LAST,
    };

	void Init();
	void First();
	void SetWaveform();
	void SetEG();
	void SetFilter();
	void SetLFO();
	void SetPWMLFO();
	void SetVCFLFO();
	void SetVCALFO();
	void Process(float *, float *);
	void NoteOn(uint8_t midi_note, uint8_t midi_velocity = MIDI_VELOCITY_MAX);
	void NoteOff(uint8_t midi_note);
	void FlashLoad(uint8_t aSlot);
	void FlashSave(uint8_t aSlot);
	void ProgramChange(uint8_t data);
	void PitchBend(int16_t data);
	void SaveToLive(VASynthSetting *);
	void LiveToSave(VASynthSetting *);

//private:

	// config
	float sample_rate_;
	uint8_t waveform_;
	float osc_mix_;
	float detune_;
	float filter_res_;
	float filter_cutoff_;
	float osc_pw_;

	float eg_a_attack_;
	float eg_a_decay_;
	float eg_a_sustain_; // level
	float eg_a_release_;
	float eg_f_attack_;
	float eg_f_decay_;
	float eg_f_amount_;
	float eg_f_sustain_; // level
	float eg_f_release_;

	uint8_t lfo_waveform_;
	float lfo_freq_;
	float lfo_amp_;

	uint8_t pwmlfo_waveform_;
	float pwmlfo_freq_;
	float pwmlfo_amp_;

	uint8_t vcflfo_waveform_;
	float vcflfo_freq_;
	float vcflfo_amp_;

	uint8_t vcalfo_waveform_;
	float vcalfo_freq_;
	float vcalfo_amp_;

	uint8_t osc2_waveform_;
	float osc2_detune_;
	float osc2_transpose_;
	uint8_t vel_select_;
	
	uint8_t midi_channel_;
	float osc2_pw_;
	
	// runtime	
	uint8_t osc_next_;
	uint8_t note_midi_[VOICES_MAX];
	float note_freq_[VOICES_MAX];

	float follow[VOICES_MAX] = {1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f};
	float velocity[VOICES_MAX];
	float bender_offset[VOICES_MAX];

	Oscillator osc_[VOICES_MAX];
	Oscillator osc2_[VOICES_MAX];
	Oscillator lfo_;
	Oscillator pwmlfo_;
	Oscillator vcflfo_;
	Oscillator vcalfo_;
	Adsr eg_a_[VOICES_MAX];
	Adsr eg_f_[VOICES_MAX];
	MoogLadder flt[VOICES_MAX];
};

#endif
