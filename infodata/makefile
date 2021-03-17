file = default
exe = $(file)

run:
ifneq ($(file), default)
	gcc \
	infodata.c \
	infodata.h \
	$(file).c -o $(exe)
else
	$(info Selecione um file valido!)
endif

