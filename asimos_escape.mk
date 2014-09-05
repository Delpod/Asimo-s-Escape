##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=asimos_escape
ConfigurationName      :=Release
WorkspacePath          := "C:\Projects\asimos_escape"
ProjectPath            := "C:\Projects\asimos_escape"
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=xvix
Date                   :=08/14/14
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:\MinGW-4.8.1\bin\g++.exe 
SharedObjectLinkerName :=C:\MinGW-4.8.1\bin\g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)SFML_STATIC $(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="asimos_escape.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:\MinGW-4.8.1\bin\windres.exe 
LinkOptions            :=  -mwindows
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)C. $(IncludeSwitch)C:/SFML-2.0/include $(IncludeSwitch)C:/Box2D/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-audio-s $(LibrarySwitch)sfml-graphics-s $(LibrarySwitch)sfml-network-s $(LibrarySwitch)sfml-window-s $(LibrarySwitch)sfml-system-s $(LibrarySwitch)Box2D 
ArLibs                 :=  "sfml-audio-s" "sfml-graphics-s" "sfml-network-s" "sfml-window-s" "sfml-system-s" "libBox2D.a" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:/SFML-2.0/lib $(LibraryPathSwitch)C:/Box2D/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:\MinGW-4.8.1\bin\ar.exe rcu
CXX      := C:\MinGW-4.8.1\bin\g++.exe 
CC       := C:\MinGW-4.8.1\bin\gcc.exe 
CXXFLAGS :=  -O2 -Wall -std=c++11  $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:\MinGW-4.8.1\bin\as.exe 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_TextureManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/zlib_adler32.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_compress.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_crc32.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_deflate.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_gzclose.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_gzlib.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_gzread.c$(ObjectSuffix) \
	$(IntermediateDirectory)/zlib_gzwrite.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_infback.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_inffast.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_inflate.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_inftrees.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_trees.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_uncompr.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_zutil.c$(ObjectSuffix) $(IntermediateDirectory)/base64_base64.cpp$(ObjectSuffix) $(IntermediateDirectory)/tinyxml2_tinyxml2.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/src_Level.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Layer.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_LevelParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_AnimatedObject.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Enemy.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_GameObject.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Lever.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_MenuButton.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Player.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Tile.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/src_Bullet.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Barrier.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Box.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix): src/Game.cpp $(IntermediateDirectory)/src_Game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Game.cpp$(DependSuffix): src/Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Game.cpp$(DependSuffix) -MM "src/Game.cpp"

$(IntermediateDirectory)/src_Game.cpp$(PreprocessSuffix): src/Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Game.cpp$(PreprocessSuffix) "src/Game.cpp"

$(IntermediateDirectory)/src_TextureManager.cpp$(ObjectSuffix): src/TextureManager.cpp $(IntermediateDirectory)/src_TextureManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/TextureManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_TextureManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_TextureManager.cpp$(DependSuffix): src/TextureManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_TextureManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_TextureManager.cpp$(DependSuffix) -MM "src/TextureManager.cpp"

$(IntermediateDirectory)/src_TextureManager.cpp$(PreprocessSuffix): src/TextureManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_TextureManager.cpp$(PreprocessSuffix) "src/TextureManager.cpp"

$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp $(IntermediateDirectory)/src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(DependSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cpp$(DependSuffix) -MM "src/main.cpp"

$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) "src/main.cpp"

$(IntermediateDirectory)/zlib_adler32.c$(ObjectSuffix): src/zlib/adler32.c $(IntermediateDirectory)/zlib_adler32.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Projects/asimos_escape/src/zlib/adler32.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_adler32.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_adler32.c$(DependSuffix): src/zlib/adler32.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_adler32.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_adler32.c$(DependSuffix) -MM "src/zlib/adler32.c"

$(IntermediateDirectory)/zlib_adler32.c$(PreprocessSuffix): src/zlib/adler32.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_adler32.c$(PreprocessSuffix) "src/zlib/adler32.c"

$(IntermediateDirectory)/zlib_compress.c$(ObjectSuffix): src/zlib/compress.c $(IntermediateDirectory)/zlib_compress.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Projects/asimos_escape/src/zlib/compress.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_compress.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_compress.c$(DependSuffix): src/zlib/compress.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_compress.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_compress.c$(DependSuffix) -MM "src/zlib/compress.c"

$(IntermediateDirectory)/zlib_compress.c$(PreprocessSuffix): src/zlib/compress.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_compress.c$(PreprocessSuffix) "src/zlib/compress.c"

$(IntermediateDirectory)/zlib_crc32.c$(ObjectSuffix): src/zlib/crc32.c $(IntermediateDirectory)/zlib_crc32.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Projects/asimos_escape/src/zlib/crc32.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_crc32.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_crc32.c$(DependSuffix): src/zlib/crc32.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_crc32.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_crc32.c$(DependSuffix) -MM "src/zlib/crc32.c"

$(IntermediateDirectory)/zlib_crc32.c$(PreprocessSuffix): src/zlib/crc32.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_crc32.c$(PreprocessSuffix) "src/zlib/crc32.c"

$(IntermediateDirectory)/zlib_deflate.c$(ObjectSuffix): src/zlib/deflate.c $(IntermediateDirectory)/zlib_deflate.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Projects/asimos_escape/src/zlib/deflate.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_deflate.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_deflate.c$(DependSuffix): src/zlib/deflate.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_deflate.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_deflate.c$(DependSuffix) -MM "src/zlib/deflate.c"

$(IntermediateDirectory)/zlib_deflate.c$(PreprocessSuffix): src/zlib/deflate.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_deflate.c$(PreprocessSuffix) "src/zlib/deflate.c"

$(IntermediateDirectory)/zlib_gzclose.c$(ObjectSuffix): src/zlib/gzclose.c $(IntermediateDirectory)/zlib_gzclose.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Projects/asimos_escape/src/zlib/gzclose.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_gzclose.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_gzclose.c$(DependSuffix): src/zlib/gzclose.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_gzclose.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_gzclose.c$(DependSuffix) -MM "src/zlib/gzclose.c"

$(IntermediateDirectory)/zlib_gzclose.c$(PreprocessSuffix): src/zlib/gzclose.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_gzclose.c$(PreprocessSuffix) "src/zlib/gzclose.c"

$(IntermediateDirectory)/zlib_gzlib.c$(ObjectSuffix): src/zlib/gzlib.c $(IntermediateDirectory)/zlib_gzlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Projects/asimos_escape/src/zlib/gzlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_gzlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_gzlib.c$(DependSuffix): src/zlib/gzlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_gzlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_gzlib.c$(DependSuffix) -MM "src/zlib/gzlib.c"

$(IntermediateDirectory)/zlib_gzlib.c$(PreprocessSuffix): src/zlib/gzlib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_gzlib.c$(PreprocessSuffix) "src/zlib/gzlib.c"

$(IntermediateDirectory)/zlib_gzread.c$(ObjectSuffix): src/zlib/gzread.c $(IntermediateDirectory)/zlib_gzread.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Projects/asimos_escape/src/zlib/gzread.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_gzread.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_gzread.c$(DependSuffix): src/zlib/gzread.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_gzread.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_gzread.c$(DependSuffix) -MM "src/zlib/gzread.c"

$(IntermediateDirectory)/zlib_gzread.c$(PreprocessSuffix): src/zlib/gzread.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_gzread.c$(PreprocessSuffix) "src/zlib/gzread.c"

$(IntermediateDirectory)/zlib_gzwrite.c$(ObjectSuffix): src/zlib/gzwrite.c $(IntermediateDirectory)/zlib_gzwrite.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Projects/asimos_escape/src/zlib/gzwrite.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_gzwrite.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_gzwrite.c$(DependSuffix): src/zlib/gzwrite.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_gzwrite.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_gzwrite.c$(DependSuffix) -MM "src/zlib/gzwrite.c"

$(IntermediateDirectory)/zlib_gzwrite.c$(PreprocessSuffix): src/zlib/gzwrite.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_gzwrite.c$(PreprocessSuffix) "src/zlib/gzwrite.c"

$(IntermediateDirectory)/zlib_infback.c$(ObjectSuffix): src/zlib/infback.c $(IntermediateDirectory)/zlib_infback.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Projects/asimos_escape/src/zlib/infback.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_infback.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_infback.c$(DependSuffix): src/zlib/infback.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_infback.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_infback.c$(DependSuffix) -MM "src/zlib/infback.c"

$(IntermediateDirectory)/zlib_infback.c$(PreprocessSuffix): src/zlib/infback.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_infback.c$(PreprocessSuffix) "src/zlib/infback.c"

$(IntermediateDirectory)/zlib_inffast.c$(ObjectSuffix): src/zlib/inffast.c $(IntermediateDirectory)/zlib_inffast.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Projects/asimos_escape/src/zlib/inffast.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_inffast.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_inffast.c$(DependSuffix): src/zlib/inffast.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_inffast.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_inffast.c$(DependSuffix) -MM "src/zlib/inffast.c"

$(IntermediateDirectory)/zlib_inffast.c$(PreprocessSuffix): src/zlib/inffast.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_inffast.c$(PreprocessSuffix) "src/zlib/inffast.c"

$(IntermediateDirectory)/zlib_inflate.c$(ObjectSuffix): src/zlib/inflate.c $(IntermediateDirectory)/zlib_inflate.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Projects/asimos_escape/src/zlib/inflate.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_inflate.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_inflate.c$(DependSuffix): src/zlib/inflate.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_inflate.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_inflate.c$(DependSuffix) -MM "src/zlib/inflate.c"

$(IntermediateDirectory)/zlib_inflate.c$(PreprocessSuffix): src/zlib/inflate.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_inflate.c$(PreprocessSuffix) "src/zlib/inflate.c"

$(IntermediateDirectory)/zlib_inftrees.c$(ObjectSuffix): src/zlib/inftrees.c $(IntermediateDirectory)/zlib_inftrees.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Projects/asimos_escape/src/zlib/inftrees.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_inftrees.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_inftrees.c$(DependSuffix): src/zlib/inftrees.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_inftrees.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_inftrees.c$(DependSuffix) -MM "src/zlib/inftrees.c"

$(IntermediateDirectory)/zlib_inftrees.c$(PreprocessSuffix): src/zlib/inftrees.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_inftrees.c$(PreprocessSuffix) "src/zlib/inftrees.c"

$(IntermediateDirectory)/zlib_trees.c$(ObjectSuffix): src/zlib/trees.c $(IntermediateDirectory)/zlib_trees.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Projects/asimos_escape/src/zlib/trees.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_trees.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_trees.c$(DependSuffix): src/zlib/trees.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_trees.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_trees.c$(DependSuffix) -MM "src/zlib/trees.c"

$(IntermediateDirectory)/zlib_trees.c$(PreprocessSuffix): src/zlib/trees.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_trees.c$(PreprocessSuffix) "src/zlib/trees.c"

$(IntermediateDirectory)/zlib_uncompr.c$(ObjectSuffix): src/zlib/uncompr.c $(IntermediateDirectory)/zlib_uncompr.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Projects/asimos_escape/src/zlib/uncompr.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_uncompr.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_uncompr.c$(DependSuffix): src/zlib/uncompr.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_uncompr.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_uncompr.c$(DependSuffix) -MM "src/zlib/uncompr.c"

$(IntermediateDirectory)/zlib_uncompr.c$(PreprocessSuffix): src/zlib/uncompr.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_uncompr.c$(PreprocessSuffix) "src/zlib/uncompr.c"

$(IntermediateDirectory)/zlib_zutil.c$(ObjectSuffix): src/zlib/zutil.c $(IntermediateDirectory)/zlib_zutil.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Projects/asimos_escape/src/zlib/zutil.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_zutil.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_zutil.c$(DependSuffix): src/zlib/zutil.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_zutil.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_zutil.c$(DependSuffix) -MM "src/zlib/zutil.c"

$(IntermediateDirectory)/zlib_zutil.c$(PreprocessSuffix): src/zlib/zutil.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_zutil.c$(PreprocessSuffix) "src/zlib/zutil.c"

$(IntermediateDirectory)/base64_base64.cpp$(ObjectSuffix): src/base64/base64.cpp $(IntermediateDirectory)/base64_base64.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/base64/base64.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/base64_base64.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/base64_base64.cpp$(DependSuffix): src/base64/base64.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/base64_base64.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/base64_base64.cpp$(DependSuffix) -MM "src/base64/base64.cpp"

$(IntermediateDirectory)/base64_base64.cpp$(PreprocessSuffix): src/base64/base64.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/base64_base64.cpp$(PreprocessSuffix) "src/base64/base64.cpp"

$(IntermediateDirectory)/tinyxml2_tinyxml2.cpp$(ObjectSuffix): src/tinyxml2/tinyxml2.cpp $(IntermediateDirectory)/tinyxml2_tinyxml2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/tinyxml2/tinyxml2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tinyxml2_tinyxml2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tinyxml2_tinyxml2.cpp$(DependSuffix): src/tinyxml2/tinyxml2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tinyxml2_tinyxml2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tinyxml2_tinyxml2.cpp$(DependSuffix) -MM "src/tinyxml2/tinyxml2.cpp"

$(IntermediateDirectory)/tinyxml2_tinyxml2.cpp$(PreprocessSuffix): src/tinyxml2/tinyxml2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tinyxml2_tinyxml2.cpp$(PreprocessSuffix) "src/tinyxml2/tinyxml2.cpp"

$(IntermediateDirectory)/src_Level.cpp$(ObjectSuffix): src/Level.cpp $(IntermediateDirectory)/src_Level.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/Level.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Level.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Level.cpp$(DependSuffix): src/Level.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Level.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Level.cpp$(DependSuffix) -MM "src/Level.cpp"

$(IntermediateDirectory)/src_Level.cpp$(PreprocessSuffix): src/Level.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Level.cpp$(PreprocessSuffix) "src/Level.cpp"

$(IntermediateDirectory)/src_Layer.cpp$(ObjectSuffix): src/Layer.cpp $(IntermediateDirectory)/src_Layer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/Layer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Layer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Layer.cpp$(DependSuffix): src/Layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Layer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Layer.cpp$(DependSuffix) -MM "src/Layer.cpp"

$(IntermediateDirectory)/src_Layer.cpp$(PreprocessSuffix): src/Layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Layer.cpp$(PreprocessSuffix) "src/Layer.cpp"

$(IntermediateDirectory)/src_LevelParser.cpp$(ObjectSuffix): src/LevelParser.cpp $(IntermediateDirectory)/src_LevelParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/LevelParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LevelParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LevelParser.cpp$(DependSuffix): src/LevelParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LevelParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LevelParser.cpp$(DependSuffix) -MM "src/LevelParser.cpp"

$(IntermediateDirectory)/src_LevelParser.cpp$(PreprocessSuffix): src/LevelParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LevelParser.cpp$(PreprocessSuffix) "src/LevelParser.cpp"

$(IntermediateDirectory)/src_AnimatedObject.cpp$(ObjectSuffix): src/AnimatedObject.cpp $(IntermediateDirectory)/src_AnimatedObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/AnimatedObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_AnimatedObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_AnimatedObject.cpp$(DependSuffix): src/AnimatedObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_AnimatedObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_AnimatedObject.cpp$(DependSuffix) -MM "src/AnimatedObject.cpp"

$(IntermediateDirectory)/src_AnimatedObject.cpp$(PreprocessSuffix): src/AnimatedObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_AnimatedObject.cpp$(PreprocessSuffix) "src/AnimatedObject.cpp"

$(IntermediateDirectory)/src_Enemy.cpp$(ObjectSuffix): src/Enemy.cpp $(IntermediateDirectory)/src_Enemy.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/Enemy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Enemy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Enemy.cpp$(DependSuffix): src/Enemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Enemy.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Enemy.cpp$(DependSuffix) -MM "src/Enemy.cpp"

$(IntermediateDirectory)/src_Enemy.cpp$(PreprocessSuffix): src/Enemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Enemy.cpp$(PreprocessSuffix) "src/Enemy.cpp"

$(IntermediateDirectory)/src_GameObject.cpp$(ObjectSuffix): src/GameObject.cpp $(IntermediateDirectory)/src_GameObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/GameObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_GameObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_GameObject.cpp$(DependSuffix): src/GameObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_GameObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_GameObject.cpp$(DependSuffix) -MM "src/GameObject.cpp"

$(IntermediateDirectory)/src_GameObject.cpp$(PreprocessSuffix): src/GameObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_GameObject.cpp$(PreprocessSuffix) "src/GameObject.cpp"

$(IntermediateDirectory)/src_Lever.cpp$(ObjectSuffix): src/Lever.cpp $(IntermediateDirectory)/src_Lever.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/Lever.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Lever.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Lever.cpp$(DependSuffix): src/Lever.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Lever.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Lever.cpp$(DependSuffix) -MM "src/Lever.cpp"

$(IntermediateDirectory)/src_Lever.cpp$(PreprocessSuffix): src/Lever.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Lever.cpp$(PreprocessSuffix) "src/Lever.cpp"

$(IntermediateDirectory)/src_MenuButton.cpp$(ObjectSuffix): src/MenuButton.cpp $(IntermediateDirectory)/src_MenuButton.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/MenuButton.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_MenuButton.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_MenuButton.cpp$(DependSuffix): src/MenuButton.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_MenuButton.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_MenuButton.cpp$(DependSuffix) -MM "src/MenuButton.cpp"

$(IntermediateDirectory)/src_MenuButton.cpp$(PreprocessSuffix): src/MenuButton.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_MenuButton.cpp$(PreprocessSuffix) "src/MenuButton.cpp"

$(IntermediateDirectory)/src_Player.cpp$(ObjectSuffix): src/Player.cpp $(IntermediateDirectory)/src_Player.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/Player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Player.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Player.cpp$(DependSuffix): src/Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Player.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Player.cpp$(DependSuffix) -MM "src/Player.cpp"

$(IntermediateDirectory)/src_Player.cpp$(PreprocessSuffix): src/Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Player.cpp$(PreprocessSuffix) "src/Player.cpp"

$(IntermediateDirectory)/src_Tile.cpp$(ObjectSuffix): src/Tile.cpp $(IntermediateDirectory)/src_Tile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/Tile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Tile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Tile.cpp$(DependSuffix): src/Tile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Tile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Tile.cpp$(DependSuffix) -MM "src/Tile.cpp"

$(IntermediateDirectory)/src_Tile.cpp$(PreprocessSuffix): src/Tile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Tile.cpp$(PreprocessSuffix) "src/Tile.cpp"

$(IntermediateDirectory)/src_Bullet.cpp$(ObjectSuffix): src/Bullet.cpp $(IntermediateDirectory)/src_Bullet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/Bullet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Bullet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Bullet.cpp$(DependSuffix): src/Bullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Bullet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Bullet.cpp$(DependSuffix) -MM "src/Bullet.cpp"

$(IntermediateDirectory)/src_Bullet.cpp$(PreprocessSuffix): src/Bullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Bullet.cpp$(PreprocessSuffix) "src/Bullet.cpp"

$(IntermediateDirectory)/src_Barrier.cpp$(ObjectSuffix): src/Barrier.cpp $(IntermediateDirectory)/src_Barrier.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/Barrier.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Barrier.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Barrier.cpp$(DependSuffix): src/Barrier.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Barrier.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Barrier.cpp$(DependSuffix) -MM "src/Barrier.cpp"

$(IntermediateDirectory)/src_Barrier.cpp$(PreprocessSuffix): src/Barrier.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Barrier.cpp$(PreprocessSuffix) "src/Barrier.cpp"

$(IntermediateDirectory)/src_Box.cpp$(ObjectSuffix): src/Box.cpp $(IntermediateDirectory)/src_Box.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/asimos_escape/src/Box.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Box.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Box.cpp$(DependSuffix): src/Box.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Box.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Box.cpp$(DependSuffix) -MM "src/Box.cpp"

$(IntermediateDirectory)/src_Box.cpp$(PreprocessSuffix): src/Box.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Box.cpp$(PreprocessSuffix) "src/Box.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_Game.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_Game.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_TextureManager.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_TextureManager.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_TextureManager.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_main.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_main.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_adler32.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_adler32.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_adler32.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_compress.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_compress.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_compress.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_crc32.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_crc32.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_crc32.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_deflate.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_deflate.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_deflate.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzclose.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzclose.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzclose.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzlib.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzlib.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzlib.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzread.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzread.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzread.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzwrite.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzwrite.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzwrite.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_infback.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_infback.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_infback.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inffast.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inffast.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inffast.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inflate.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inflate.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inflate.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inftrees.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inftrees.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inftrees.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_trees.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_trees.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_trees.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_uncompr.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_uncompr.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_uncompr.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_zutil.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_zutil.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_zutil.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/base64_base64.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/base64_base64.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/base64_base64.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml2_tinyxml2.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml2_tinyxml2.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml2_tinyxml2.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_Level.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_Level.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_Level.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_Layer.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_Layer.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_Layer.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_LevelParser.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_LevelParser.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_LevelParser.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_AnimatedObject.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_AnimatedObject.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_AnimatedObject.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_Enemy.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_Enemy.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_Enemy.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_GameObject.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_GameObject.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_GameObject.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_Lever.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_Lever.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_Lever.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_MenuButton.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_MenuButton.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_MenuButton.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_Player.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_Player.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_Player.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_Tile.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_Tile.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_Tile.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_Bullet.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_Bullet.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_Bullet.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_Barrier.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_Barrier.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_Barrier.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_Box.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_Box.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_Box.cpp$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) ".build-release/asimos_escape"


