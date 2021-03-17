file = default
libs = "F:\Projects\c\UFRR-URI-ED-1\infodata"
exe = $(file)

run:
ifneq ($(file), default)
	gcc \
	$(libs)\*.c \
	$(libs)\*.h \
	$(file).c -o $(exe)
else
	$(info Selecione um file valido!)
endif