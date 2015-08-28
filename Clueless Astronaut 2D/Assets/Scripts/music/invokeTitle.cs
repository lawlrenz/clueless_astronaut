using UnityEngine;
using System.Collections;

public class invokeTitle : MonoBehaviour {

	public AudioClip ac;

	// Use this for initialization
	void Start () {
		GameObject go = GameObject.Find ("bgMusicHandler");
		go.GetComponent<AudioSource> ().clip = ac;
		go.GetComponent<AudioSource> ().Play ();

	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
