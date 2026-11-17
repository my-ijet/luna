.PHONY: tags

tags:
	ctags -R --fields=+S --c-kinds=+px --languages=C --map-C=+.h --exclude=build --exclude=.git .
