import os
import shutil


cd_path = "cd ./jni"
ndk_path = " /home/rainbow/Android/Sdk/ndk/21.1.6352462/ndk-build "

os.system(cd_path +"&&"+ ndk_path)
# if not os.path.exists("./Install/obj"):
os.mkdir("./Install")
os.mkdir("./Install/obj")
for root, dirs, files in os.walk("./obj"):
    for file in files:
        src_file = os.path.join(root, file)
        shutil.copy(src_file, "./Install/obj")
        print(src_file)

# if not os.path.exists("./Install/libs"):
os.mkdir("./Install/libs")
for root, dirs, files in os.walk("./libs"):
    for file in files:
        src_file = os.path.join(root, file)
        shutil.copy(src_file, "./Install/libs")
        print(src_file)

if not os.path.exists("./Install/include"):
    os.mkdir("./Install/include")
for root, dirs, files in os.walk("./include"):
    for file in files:
        src_file = os.path.join(root, file)
        shutil.copy(src_file, "./Install/include")
        print(src_file)

shutil.rmtree("./libs")
shutil.rmtree("./obj")