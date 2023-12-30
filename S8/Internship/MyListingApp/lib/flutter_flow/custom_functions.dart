import 'dart:convert';
import 'dart:math' as math;

import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:intl/intl.dart';
import 'package:timeago/timeago.dart' as timeago;
import 'lat_lng.dart';
import 'place.dart';
import 'uploaded_file.dart';
import '/backend/backend.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import '/auth/firebase_auth/auth_util.dart';

String? returnTags(List<String>? listTags) {
  var res = "";

  if (listTags != null) {
    for (var i = 0; i < (listTags.length); i++) {
      res += listTags[i] + "  ";
    }
  }

  return res;
}

bool showSearchResult(
  String textSearchFor,
  String textSearchInTitle,
  String progress,
  bool boolInProgressButton,
  bool? favorite,
  bool boolFavoriteButton,
  bool boolToStartButton,
  bool boolFinishedButton,
  bool boolReadButton,
  bool boolWatchButton,
  String watchRead,
  String? textSearchInAuthor,
  List<String>? tags,
  List<String>? clickedTags,
  String type,
  List<String>? clickedTypes,
) {
  bool init = true;
  List<String> clickedFilters = [];

  if (clickedTags != null) {
    clickedFilters.addAll(clickedTags);
  }
  if (clickedTypes != null) {
    clickedFilters.addAll(clickedTypes);
  }

  if (textSearchInTitle.toLowerCase().contains(textSearchFor.toLowerCase()) ||
      textSearchInAuthor!.toLowerCase().contains(textSearchFor.toLowerCase())) {
    init = true;
  } else {
    return false;
  }

  if (boolInProgressButton) {
    if (progress == "In progress") {
      init = true;
    } else {
      return false;
    }
  }

  if (boolToStartButton) {
    if (progress == "To start") {
      init = true;
    } else {
      return false;
    }
  }

  if (boolFinishedButton) {
    if (progress == "Finished") {
      init = true;
    } else {
      return false;
    }
  }

  if (boolFavoriteButton) {
    if (favorite!) {
      init = true;
    } else {
      return false;
    }
  }

  if (boolReadButton) {
    if (watchRead == "Read") {
      init = true;
    } else {
      return false;
    }
  }

  if (boolWatchButton) {
    if (watchRead == "Watch") {
      init = true;
    } else {
      return false;
    }
  }

  int i = 0;
  if (clickedFilters.isNotEmpty) {
    for (String clickedFilter in clickedFilters) {
      if (type.toLowerCase() == clickedFilter.toLowerCase()) {
        i = 1;
        break;
      } else {
        for (String tag in tags!) {
          if (tag.toLowerCase() == clickedFilter.toLowerCase()) {
            i = 1;
            break;
          }
        }
      }
    }
  }

  if (clickedFilters.isEmpty) {
    init = true;
  } else {
    if (i == 1) {
      init = true;
    } else {
      return false;
    }
  }

  return init;
}

bool isSequel(
  bool boolFinished,
  String? mediaProgress,
  String userProgress,
) {
  if (boolFinished &&
      mediaProgress == "Maybe sequel" &&
      userProgress == "Finished") {
    return true;
  } else {
    return false;
  }
}

bool checkHasMail(String uid) {
  bool res = false; // Initialize with false for no email

  final userRef = FirebaseFirestore.instance.collection('users').doc(uid);
  userRef.get().then((userData) {
    if (userData.exists) {
      final email = userData.get('email') as String?;
      if (email != null) {
        res = true;
      } else {
        res = false;
      }
    }
  });

  return res;
}

String getPassword(String? uid) {
  String password = "";

  final userRef = FirebaseFirestore.instance.collection('users').doc(uid);
  userRef.get().then((userData) {
    if (userData.exists) {
      password = userData.get('password') as String;
    }
  });

  return password;
}

bool itemInList(
  List<String> list,
  String item,
) {
  return list.contains(item);
}
