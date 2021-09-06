/*
 * Copyright (C) the libgit2 contributors. All rights reserved.
 *
 * This file is part of libgit2, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included COPYING file.
 */
#ifndef INCLUDE_checkout_h__
#define INCLUDE_checkout_h__

#include "common.h"

#include "git2/checkout.h"
#include "iterator.h"

/**
 * Do not do a checkout and do not fire callbacks; this is useful
 * for internal functions that will perform the checkout themselves
 * but need to pass checkout options into another function, for
 * example, `git_clone`.
 *
 * This is defined as `GIT_CHECKOUT_RESERVED` in the public API to
 * ensure that we do not accidentally re-use it.
 */
#define GIT_CHECKOUT__HARD_STOP (1u << 31)

/**
 * Update the working directory to match the target iterator.  The
 * expected baseline value can be passed in via the checkout options
 * or else will default to the HEAD commit.
 */
extern int git_checkout_iterator(
	git_iterator *target,
	git_index *index,
	const git_checkout_options *opts);

#endif
