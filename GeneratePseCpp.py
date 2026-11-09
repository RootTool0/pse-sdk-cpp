import os
from datetime import datetime

INPUT = [
    # pse-sdk
    {"type": "code", "value": "#ifdef PSE_SDK_CPP_CORE_IMPLEMENTATION"},
    {"type": "code", "value": "#define PSE_EXPORTS"},
    {"type": "code", "value": "#endif"},
    
    {"type": "file", "value": "External/pse-sdk/include/enums.h"},
    {"type": "file", "value": "External/pse-sdk/include/structures.h"},
    {"type": "file", "value": "External/pse-sdk/include/pse.h"},
    
    {"type": "code", "value": "#ifdef PSE_SDK_CPP_CORE_IMPLEMENTATION"},
    {"type": "file", "value": "External/pse-sdk/source/pse.cpp"},
    {"type": "code", "value": "#endif"},
    
    {"type": "code", "value": "#include <cmath>"},
    {"type": "file", "value": "External/pse-sdk/include/pse.hpp"},
    
    # pse-sdk-cpp
    {"type": "file", "value": "Source/Misc.h"},
    {"type": "file", "value": "Source/Game.h"},
    {"type": "file", "value": "Source/Player.h"},
    {"type": "file", "value": "Source/SolverGun.h"},
    {"type": "file", "value": "Source/Flashlight.h"},
    {"type": "file", "value": "Source/StaticMesh.h"},
    # E2A0
    {"type": "file", "value": "Source/DynamicMesh.h"},
    {"type": "file", "value": "Source/Element.h"},
    {"type": "file", "value": "Source/Elements/AntiExpropriationField.h"},
    {"type": "file", "value": "Source/Elements/Button.h"},
    {"type": "file", "value": "Source/Elements/CubeDropper.h"},
    {"type": "file", "value": "Source/Elements/Door.h"},
    {"type": "file", "value": "Source/Elements/EntryElevator.h"},
    {"type": "file", "value": "Source/Elements/ExitElevator.h"},
    {"type": "file", "value": "Source/Elements/FaithPlate.h"},
    {"type": "file", "value": "Source/Elements/Flashlight.h"},
    {"type": "file", "value": "Source/Elements/Indicator.h"},
    {"type": "file", "value": "Source/Elements/Lamp.h"},
    {"type": "file", "value": "Source/Elements/LaserCube.h"},
    {"type": "file", "value": "Source/Elements/LaserPanel.h"},
    {"type": "file", "value": "Source/Elements/LaserRelay.h"},
    {"type": "file", "value": "Source/Elements/LaserRx.h"},
    {"type": "file", "value": "Source/Elements/LaserTx.h"},
    {"type": "file", "value": "Source/Elements/Panel.h"},
    {"type": "file", "value": "Source/Elements/PedestalButton.h"},
    {"type": "file", "value": "Source/Elements/SolverButton.h"},
    {"type": "file", "value": "Source/Elements/SolverGunPedestal.h"},
    {"type": "file", "value": "Source/Elements/Stairs.h"},
    {"type": "file", "value": "Source/Elements/Trigger.h"},
    {"type": "file", "value": "Source/Elements/WeightCube.h"},
    {"type": "file", "value": "Source/Elements/Window.h"}
]

OUTPUT_FILE = "PseCpp.h"

EXCLUDE_LINES = [
    "#pragma once",
    "#include \"pse.h\"",
    "#include \"enums.h\"",
    "#include \"structures.h\"",
    "#include \"pse/pse.h\""
]

try:
    with open(OUTPUT_FILE, 'w', encoding='utf-8') as outfile:
        outfile.write("// pse-sdk-cpp\n\n")
        outfile.write(f"// Build date: {datetime.utcnow().strftime('%d %B %Y | %H:%M:%S UTC')}\n\n")
        outfile.write("#pragma once\n\n")
        
        for item in INPUT:
            item_type = item.get("type")
            item_value = item.get("value", "")
            
            if item_type == "code":
                print(f"[Generate Pse Cpp] [OK] Processing code: {item_value}")
                outfile.write(item_value)
                outfile.write("\n")
                continue
            
            if item_type == "file":
                file_path = item_value
                if not os.path.exists(file_path):
                    print(f"[Generate Pse Cpp] [Warning] File not found and skipped: {file_path}")
                    continue
                
                print(f"[Generate Pse Cpp] [OK] Processing file {file_path}")
                
                with open(file_path, 'r', encoding='utf-8') as infile:
                    for line in infile:
                        if any(line.lstrip().startswith(ex_line) for ex_line in EXCLUDE_LINES): continue
                        
                        outfile.write(line)
                
                outfile.write("\n")
            
    print(f"[Generate Pse Cpp] [OK] Merging completed. Result saved to: {OUTPUT_FILE}")
    
except Exception as e:
    print(f"[Generate Pse Cpp] [Error] Error occurred: {e}")
