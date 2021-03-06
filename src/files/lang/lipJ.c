#include <ultra64.h>

char *lang[] = {
	/*0x00*/ "|Background - \n\nA craft carrying Institute advisors has been shot down in Nevada. Debris from the crash and the bodies of the advisors have been taken to Area 51. A spy inside the base has managed to get footage to the Institute of a possible survivor. This mission is to rescue that survivor.\n\n|Carrington - \n\nYou need to cover our tracks and rescue our friend as fast as you can. A disguise will help you do that but it won't last forever, so make good use of it. Wipe out their records and make sure there are no more survivors we are unaware of. Time is pressing, so hurry.\n\n|Objective One: - Obtain Lab Technician Disguise\n\nFind a Lab Technician's outfit and use it to get past the security. Once you have move fast, since the theft won't go unnoticed for long.\n\n|Objective Two: - Destroy Computer Research Records\n\nAny information that the Area 51 techs were able to get from the crash wreckage and objects must be wiped from their databases. Install a virus using the Data Uplink device, but be alert for the possibility that this may set off an alarm.\n\n|Objective Three: - Locate Conspiracy Evidence\n\nJohnathan's report made reference to a tissue containment unit where organic samples are stored at extremely low temperatures. He believes that it could be used to cryogenically freeze bodies before surgery or dissection. Find this area and confirm the deaths of the three other passengers of the craft.\n\n|Objective Four: - Gain Access to Autopsy Lab\n\nA premature autopsy will soon be taking place in one of the secure medical laboratories. It will be locked to those without clearance, so get a card with the appropriate level to get in. Not all cards will work, and there may be door guards as well.\n\n|Objective Five: - Rescue The Crash Survivor\n\nOnce you are in the Lab you will have to get into the autopsy chamber before any harm comes to the subject. The scientists will try to kill him if they think he's alive, or will attempt to damage what they think is a corpse as soon as they see you. Yet again, speed is vital.\n\nEND\n",
	/*0x01*/ "AREA 51 - MEDLABS\n",
	/*0x02*/ "|Background - \n\nA craft carrying Institute advisors has been shot down in Nevada. Debris from the crash and the bodies of the advisors have been taken to Area 51. A spy inside the base has managed to get footage to the Institute of a possible survivor. This mission is to rescue that survivor.\n\n|Carrington - \n\nYou need to cover our tracks and rescue our friend as fast as you can. A disguise will help you do that but it won't last forever, so make good use of it. Wipe out their records and make sure there are no more survivors we are unaware of. Time is pressing, so hurry.\n\n|Objective One: - Obtain Lab Technician Disguise\n\nFind a Lab Technician's outfit and use it to get past the security. Once you have move fast, since the theft won't go unnoticed for long.\n\n|Objective Two: - Locate Conspiracy Evidence\n\nJohnathan's report made reference to a tissue containment unit where organic samples are stored at extremely low temperatures. He believes that it could be used to cryogenically freeze bodies before surgery or dissection. Find this area and confirm the deaths of the three other passengers of the craft.\n\n|Objective Three: - Gain Access to Autopsy Lab\n\nA premature autopsy will soon be taking place in one of the secure medical laboratories. It will be locked to those without clearance, so get a card with the appropriate level to get in. Not all cards will work, and there may be door guards as well.\n\n|Objective Four: - Rescue The Crash Survivor\n\nOnce you are in the Lab you will have to get into the autopsy chamber before any harm comes to the subject. The scientists will try to kill him if they think he's alive, or will attempt to damage what they think is a corpse as soon as they see you. Yet again, speed is vital.\n\nEND\n",
	/*0x03*/ "|Background - \n\nA craft carrying Institute advisors has been shot down in Nevada. Debris from the crash and the bodies of the advisors have been taken to Area 51. A spy inside the base has managed to get footage to the Institute of a possible survivor. This mission is to rescue that survivor.\n\n|Carrington - \n\nYou need to cover our tracks and rescue our friend as fast as you can. A disguise will help you do that but it won't last forever, so make good use of it. Wipe out their records and make sure there are no more survivors we are unaware of. Time is pressing, so hurry.\n\n|Objective One: - Obtain Lab Technician Disguise\n\nFind a Lab Technician's outfit and use it to get past the security. Once you have move fast, since the theft won't go unnoticed for long.\n\n|Objective Two: - Gain Access to Autopsy Lab\n\nA premature autopsy will soon be taking place in one of the secure medical laboratories. It will be locked to those without clearance, so get a card with the appropriate level to get in. Not all cards will work, and there may be door guards as well.\n\n|Objective Three: - Rescue The Crash Survivor\n\nOnce you are in the Lab you will have to get into the autopsy chamber before any harm comes to the subject. The scientists will try to kill him if they think he's alive, or will attempt to damage what they think is a corpse as soon as they see you. Yet again, speed is vital.\n\nEND\n",
	/*0x04*/ "\n",
	/*0x05*/ "\n",
	/*0x06*/ "\n",
	/*0x07*/ "\n",
	/*0x08*/ "\n",
	/*0x09*/ "Obtain Laboratory Technician Disguise\n",
	/*0x0a*/ "Destroy Computer Records\n",
	/*0x0b*/ "Locate Conspiracy Evidence\n",
	/*0x0c*/ "Gain Access To Autopsy Lab\n",
	/*0x0d*/ "Rescue Elvis\n",
	/*0x0e*/ "Research Records Destroyed\n",
	/*0x0f*/ "Obtain Lab CLothes\n",
	/*0x10*/ "Lab Techs\n",
	/*0x11*/ "Lab Clothes\n",
	/*0x12*/ "Lab Clothes\n",
	/*0x13*/ "Picked up Lab Clothes\n",
	/*0x14*/ "Access To Door Control Systems Denied\n",
	/*0x15*/ "Access To Light Control Systems Denied\n",
	/*0x16*/ "Access To Security Control Systems Denied\n",
	/*0x17*/ "Virus Downloaded To Console\n",
	/*0x18*/ "Obtain Data Uplink\n",
	/*0x19*/ "Lab Techs\n",
	/*0x1a*/ "Data Uplink\n",
	/*0x1b*/ "Data Uplink\n",
	/*0x1c*/ "Picked up Data Uplink\n",
	/*0x1d*/ "Laboratory Accessed Successfully\n",
	/*0x1e*/ "Data Uplink Connected\n",
	/*0x1f*/ "Data Uplink Connection Broken\n",
	/*0x20*/ "Obtain Medlab2 Keycard\n",
	/*0x21*/ "Guards\n",
	/*0x22*/ "Medlab 2 Keycard\n",
	/*0x23*/ "Medlab 2 Keycard\n",
	/*0x24*/ "Picked up Medlab 2 Keycard.\n",
	/*0x25*/ "Who are you?\n",
	/*0x26*/ "Hey - you've got my clothes\n",
	/*0x27*/ "Help - Help\n",
	/*0x28*/ "Don't shoot me\n",
	/*0x29*/ "Oh my god - a gun!\n",
	/*0x2a*/ "There's an intruder in the complex\n",
	/*0x2b*/ "Give me back my clothes - or else\n",
	/*0x2c*/ "Right - you've asked for it!\n",
	/*0x2d*/ "Give me my clothes\n",
	/*0x2e*/ "I don't have much time before the body's discovered\n",
	/*0x2f*/ "The enemy has discovered the disguise\n",
	/*0x30*/ "Virus has already been downloaded\n",
	/*0x31*/ "Initiating virus download\n",
	/*0x32*/ "So, you've got here at last.\n",
	/*0x33*/ "Hey, you're not.... SECURITY ALERT\n",
	/*0x34*/ "Not guns allowed in here - put away you're weapon.\n",
	/*0x35*/ "I won't ask you again - ditch the weapon\n",
	/*0x36*/ "Right - I'm calling security.\n",
	/*0x37*/ "Everyone's been waiting for you...\n",
	/*0x38*/ "Critical Mission Personnel Killed.\n",
	/*0x39*/ "Cannot gain access to autopsy lab.\n",
	/*0x3a*/ "Hey, that's not Harry. It's an intruder.\n",
	/*0x3b*/ "Obtain Op-room Keycard\n",
	/*0x3c*/ "Guards\n",
	/*0x3d*/ "Oproom Keycard\n",
	/*0x3e*/ "Oproom Keycard\n",
	/*0x3f*/ "Picked up Operation Room Keycard.\n",
	/*0x40*/ "Elvis has been Killed.\n",
	/*0x41*/ "Get The Hell Out Of Here!\n",
	/*0x42*/ "Containment Unit Raised Up\n",
	/*0x43*/ "Containment Unit Lowered Down\n",
	/*0x44*/ "Mission Critical Equipment Destroyed\n",
	/*0x45*/ "Obtain X-ray scanner\n",
	/*0x46*/ "\n",
	/*0x47*/ "X-ray scanner\n",
	/*0x48*/ "X-ray scanner\n",
	/*0x49*/ "Picked up X-ray scanner.\n",
	/*0x4a*/ "Scanner Target Aquired\n",
	/*0x4b*/ "Target ID confirmed - XT origin\n",
	/*0x4c*/ "Scanner lock lost.\n",
	/*0x4d*/ "Disguise has been worn.\n",
	/*0x4e*/ "The showers... now, if I can convince someone\nto part with their uniform...\n",
	/*0x4f*/ "The temperature's dropping... you must be \nclose to the cryo room.\n",
	/*0x50*/ "The air's heavily recycled round here - must\n be near the autopsy lab.\n",
	/*0x51*/ "There he is, Jo! Hurry or you'll be too late!\n",
	/*0x52*/ "Leave this area now.\n",
	/*0x53*/ "Should you be in here?\n",
	/*0x54*/ "Holy.....\n",
	/*0x55*/ "It's a spy!\n",
	/*0x56*/ "Warn the others...\n",
	/*0x57*/ "Impostor!\n",
	/*0x58*/ "Lighting Systems Overloaded.\n",
	/*0x59*/ "The problem you have is that there is no way to sneak into the research section. The only way in available to you is a weak section of wall I've marked in the room beyond the stores. It can be destroyed with explosives.",
	/*0x5a*/ "Doesn't sound like a problem to me. Where are these explosives?",
	/*0x5b*/ "In that crate.",
	/*0x5c*/ "Cute. Very cute.",
	/*0x5d*/ "By the way, the stores are crawling with guards. It may go against your nature, but try sneaking through rather than blasting everything.",
	/*0x5e*/ "Certainly. Any other pearls of wisdom?",
	/*0x5f*/ "That crate...",
	/*0x60*/ "Yes?",
	/*0x61*/ "It really doesn't like being shot.",
	/*0x62*/ "Great. Now, if I can just fight the urge to report him to Base Security...",
	/*0x63*/ "Put your hands up and step away from the alien.",
	/*0x64*/ "What the hell do you think you're doing? This is supposed to be a sealed room! Don't you know anything about autopsy procedures?",
	/*0x65*/ "Don't make me tell you again, Doctor. And turn that laser off.",
	/*0x66*/ "Director Easton will hear about this, young lady.",
	/*0x67*/ "Of course he's going to hear of it, you moron. I've just got into his top secret base and now I'm stealing his alien.",
	/*0x68*/ "You can't take that! It's government property! This is intolerable! It's... it's... unprofessional!!",
	/*0x69*/ NULL,
	/*0x6a*/ NULL,
	/*0x6b*/ NULL,
};
