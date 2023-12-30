import 'dart:async';

import 'package:collection/collection.dart';

import '/backend/schema/util/firestore_util.dart';
import '/backend/schema/util/schema_util.dart';

import 'index.dart';
import '/flutter_flow/flutter_flow_util.dart';

class MediasRecord extends FirestoreRecord {
  MediasRecord._(
    DocumentReference reference,
    Map<String, dynamic> data,
  ) : super(reference, data) {
    _initializeFields();
  }

  // "title" field.
  String? _title;
  String get title => _title ?? '';
  bool hasTitle() => _title != null;

  // "type" field.
  String? _type;
  String get type => _type ?? '';
  bool hasType() => _type != null;

  // "tags" field.
  List<String>? _tags;
  List<String> get tags => _tags ?? const [];
  bool hasTags() => _tags != null;

  // "favorite" field.
  bool? _favorite;
  bool get favorite => _favorite ?? false;
  bool hasFavorite() => _favorite != null;

  // "stop" field.
  String? _stop;
  String get stop => _stop ?? '';
  bool hasStop() => _stop != null;

  // "image" field.
  String? _image;
  String get image => _image ?? '';
  bool hasImage() => _image != null;

  // "media_progress" field.
  String? _mediaProgress;
  String get mediaProgress => _mediaProgress ?? '';
  bool hasMediaProgress() => _mediaProgress != null;

  // "progress" field.
  String? _progress;
  String get progress => _progress ?? '';
  bool hasProgress() => _progress != null;

  // "authors" field.
  String? _authors;
  String get authors => _authors ?? '';
  bool hasAuthors() => _authors != null;

  // "watch_read" field.
  String? _watchRead;
  String get watchRead => _watchRead ?? '';
  bool hasWatchRead() => _watchRead != null;

  // "details" field.
  String? _details;
  String get details => _details ?? '';
  bool hasDetails() => _details != null;

  // "url" field.
  String? _url;
  String get url => _url ?? '';
  bool hasUrl() => _url != null;

  DocumentReference get parentReference => reference.parent.parent!;

  void _initializeFields() {
    _title = snapshotData['title'] as String?;
    _type = snapshotData['type'] as String?;
    _tags = getDataList(snapshotData['tags']);
    _favorite = snapshotData['favorite'] as bool?;
    _stop = snapshotData['stop'] as String?;
    _image = snapshotData['image'] as String?;
    _mediaProgress = snapshotData['media_progress'] as String?;
    _progress = snapshotData['progress'] as String?;
    _authors = snapshotData['authors'] as String?;
    _watchRead = snapshotData['watch_read'] as String?;
    _details = snapshotData['details'] as String?;
    _url = snapshotData['url'] as String?;
  }

  static Query<Map<String, dynamic>> collection([DocumentReference? parent]) =>
      parent != null
          ? parent.collection('medias')
          : FirebaseFirestore.instance.collectionGroup('medias');

  static DocumentReference createDoc(DocumentReference parent) =>
      parent.collection('medias').doc();

  static Stream<MediasRecord> getDocument(DocumentReference ref) =>
      ref.snapshots().map((s) => MediasRecord.fromSnapshot(s));

  static Future<MediasRecord> getDocumentOnce(DocumentReference ref) =>
      ref.get().then((s) => MediasRecord.fromSnapshot(s));

  static MediasRecord fromSnapshot(DocumentSnapshot snapshot) => MediasRecord._(
        snapshot.reference,
        mapFromFirestore(snapshot.data() as Map<String, dynamic>),
      );

  static MediasRecord getDocumentFromData(
    Map<String, dynamic> data,
    DocumentReference reference,
  ) =>
      MediasRecord._(reference, mapFromFirestore(data));

  @override
  String toString() =>
      'MediasRecord(reference: ${reference.path}, data: $snapshotData)';

  @override
  int get hashCode => reference.path.hashCode;

  @override
  bool operator ==(other) =>
      other is MediasRecord &&
      reference.path.hashCode == other.reference.path.hashCode;
}

Map<String, dynamic> createMediasRecordData({
  String? title,
  String? type,
  bool? favorite,
  String? stop,
  String? image,
  String? mediaProgress,
  String? progress,
  String? authors,
  String? watchRead,
  String? details,
  String? url,
}) {
  final firestoreData = mapToFirestore(
    <String, dynamic>{
      'title': title,
      'type': type,
      'favorite': favorite,
      'stop': stop,
      'image': image,
      'media_progress': mediaProgress,
      'progress': progress,
      'authors': authors,
      'watch_read': watchRead,
      'details': details,
      'url': url,
    }.withoutNulls,
  );

  return firestoreData;
}

class MediasRecordDocumentEquality implements Equality<MediasRecord> {
  const MediasRecordDocumentEquality();

  @override
  bool equals(MediasRecord? e1, MediasRecord? e2) {
    const listEquality = ListEquality();
    return e1?.title == e2?.title &&
        e1?.type == e2?.type &&
        listEquality.equals(e1?.tags, e2?.tags) &&
        e1?.favorite == e2?.favorite &&
        e1?.stop == e2?.stop &&
        e1?.image == e2?.image &&
        e1?.mediaProgress == e2?.mediaProgress &&
        e1?.progress == e2?.progress &&
        e1?.authors == e2?.authors &&
        e1?.watchRead == e2?.watchRead &&
        e1?.details == e2?.details &&
        e1?.url == e2?.url;
  }

  @override
  int hash(MediasRecord? e) => const ListEquality().hash([
        e?.title,
        e?.type,
        e?.tags,
        e?.favorite,
        e?.stop,
        e?.image,
        e?.mediaProgress,
        e?.progress,
        e?.authors,
        e?.watchRead,
        e?.details,
        e?.url
      ]);

  @override
  bool isValidKey(Object? o) => o is MediasRecord;
}
