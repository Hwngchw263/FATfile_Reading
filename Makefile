#Name project
NAME := main

#Output path
PATH_OUTPUT := ./Output
#Compiler
CC = gcc
#Flag
CCFLAGS = -c

#Library
#Include files
INC_DIRS = Library/inc			
#Source files
SRC_DIRS = User\
			Library/src

# #All include and source direction
# ALL_INC_DIRS = $(INC_DIRS)
# ALL_SRC_DIRS +=  User\
# 				 $(SRC_DIRS)
#All include file and source file in project
INC_FILES += $(foreach INC_DIRS,$(INC_DIRS),$(wildcard $(INC_DIRS)/*))
SRC_FILES += $(foreach SRC_DIRS,$(SRC_DIRS),$(wildcard $(SRC_DIRS)/*))

#Object files
OBJ_FILES := $(notdir $(SRC_FILES))
OBJ_FILES := $(subst .c,.o,$(OBJ_FILES))
PATH_OBJ := $(foreach OBJ_FILES,$(OBJ_FILES),$(PATH_OUTPUT)/$(OBJ_FILES))

#CC options for INC_DIRS
INC_DIRS_OPT = $(foreach INC_DIRS,$(INC_DIRS),-I $(INC_DIRS))

vpath %.c $(SRC_DIRS)

build:$(NAME).exe

#Make object file from source file
%.o:%.c
	$(CC) $(INC_DIRS_OPT) $(CCFLAGS) $^ -o $(PATH_OUTPUT)/$@
	
#Linking object files
$(NAME).exe:$(OBJ_FILES)
	$(CC) $(PATH_OBJ) -o $(PATH_OUTPUT)/$@
	
run:
	$(PATH_OUTPUT)/$(NAME).exe

clean:
	rm -rf ./Output/*
	
print-%:
	@echo $($(subst print-,,$@))
	