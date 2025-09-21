# REPORT.md
**Student:** Rameesha Shakeel  
**Roll No:** BSDSF23A023  
**Course:** Operating Systems  
**Assignment:** Programming Assignment – 01

## Part 2 Report Questions
### 1. Explain the linking rule in this part's Makefile: `$(TARGET): $(OBJECTS)`. How does it differ from a Makefile rule that links against a library?
The rule `$(TARGET): $(OBJECTS)` declares that the final target (executable) depends on the object files. When any object changes, make rebuilds those objects then runs the link command to produce the executable. In this direct compilation approach, each .o contains compiled code of translation units and the final link step combines them.

When linking against a library (static `.a` or dynamic `.so`), the target depends on the library file instead of the individual object files. The Makefile will first build the library (archive or shared object) and then link the executable against the library using `-L` and `-l` flags. The difference: using a library hides internal object files inside the archive and can speed linking and compilation when only parts of the library change.

### 2. What is a git tag and why is it useful in a project? Difference between lightweight and annotated tag?
A git tag marks a specific commit as important (e.g., a release). It is useful for marking release points, making it easy to check out exact states, and integrating with GitHub Releases.

- Lightweight tag: just a pointer to a commit (like a branch that doesn't move).
- Annotated tag: stores extra metadata (tagger name, date, message) and is an actual Git object. Annotated tags are preferable for releases.

### 3. Purpose of creating a "Release" on GitHub? Significance of attaching binaries?
A GitHub Release packages a tagged commit with human-readable release notes and binary assets. Attaching binaries helps users download compiled artifacts without building from source, useful for graders or users who want to test quickly.

## Part 3 Report Questions
1. Compare the Makefile from Part 2 and Part 3. Key differences:
- Part 2: compiles each source file and links them together directly.
- Part 3: builds object files and archives them into a static library using `ar` (and `ranlib`), then links the final executable with `-L` and `-lmyutils`. Additional targets to create and list the archive are present.

2. Purpose of `ar` and why `ranlib` is used:
`ar` creates an archive `.a` by combining object files. `ranlib` generates or updates the library index (symbol table) inside the archive so linkers can quickly find symbols. On many toolchains `ar` already does it or `ranlib` is a no-op, but `ranlib` is kept for portability.

3. When running `nm` on `client_static`, are symbols like `mystrlen` present? What does it tell about static linking?
Yes, `nm` on a statically linked executable often shows included symbols since the code was copied into the executable. This indicates static linking embeds library code into the final binary, making the executable self-contained.

## Part 4 Report Questions
1. What is Position-Independent Code (-fPIC) and why required for shared libs?
`-fPIC` generates code that can execute correctly regardless of its absolute memory address by using relative addressing. Shared libraries must be relocatable because the dynamic loader can place them at different addresses in different processes.

2. Explain the difference in file size between static and dynamic clients.
Static client includes library code inside the executable -> larger file. Dynamic client keeps code in `.so`, so executable is smaller and the library is shared among processes.

3. What is LD_LIBRARY_PATH and why necessary here?
`LD_LIBRARY_PATH` tells the dynamic loader where to search for shared libraries at runtime. We used it to point to our project's `lib/` because `/usr/lib` or standard paths did not contain `libmyutils.so`, so the loader couldn't find it otherwise.

## Part 5 Report Questions
(Brief answers are included in the project README and individual man pages)

---

**Note:** This REPORT.md is intentionally concise. Expand or reword answers as necessary before submission to reflect your understanding.
