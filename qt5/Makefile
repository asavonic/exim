QMAKE = qmake-qt5

all: build/libeximplatforminputcontext.so

.PHONY: build/libeximplatforminputcontext.so

build/Makefile: exim.pro
	mkdir -p build
	cd build && $(QMAKE) ..

build/libeximplatforminputcontext.so: build/Makefile
	$(MAKE) -C build
	mkdir -p build/platforminputcontexts
	ln -rsf build/libeximplatforminputcontext.so build/platforminputcontexts/

# Run Nomacs program to play around.
# TODO: add unittests
test:
	env QT_PLUGIN_PATH=build QT_DEBUG_PLUGINS=1 QDBUS_DEBUG=1 QT_IM_MODULE=exim nomacs
clean:
	rm -rf build
